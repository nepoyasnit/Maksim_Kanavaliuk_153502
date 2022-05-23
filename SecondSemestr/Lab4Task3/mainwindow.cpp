#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void Normalize(vector<int>& c) {
    for (int i = 0; i < c.size() - 1; ++i) {
        c[i + 1] += c[i] >> 1;
        c[i] &= 1;
    }
}

void AddZero(vector<int>& c, int x) {
    c.resize(x + 1);
    c[x] = 0;
}

vector<int> AddNum(const vector<int>& a, const vector<int>& b, int k) {

    vector<int> c(std::max(a.size(), b.size()) + 1);

    for (int i = 0; i < c.size(); ++i) {
        if (i < a.size()) {
            c[i] += a[i];
        }
        if (i < b.size()) {
            c[i] += b[i];
        }
    }

    Normalize(c);
    AddZero(c, k);

    return c;
}

int GetBit(vector<int> v, int b) {
    return v[b] & 1;
}

vector<int> Multiply(const vector<int>& a, int x, int k) {

    vector<int> b = a;
    b.push_back(0);

    for (int i = 0; i < b.size(); ++i) {
        b[i] *= x;
    }

    Normalize(b);
    AddZero(b, k);

    return b;
}

void GenerateSequence(vector<int> n, const vector<vector<int>>& p, int k, int i, vector<pair<int, vector<int>> >& v) {
    if (i == k) {
        n.resize(k + 1);
        if (GetBit(n, k)) {
            v.push_back(make_pair(k, n));
        }
        return;
    }

    if (GetBit(n, i)) {
        return;
    }

    GenerateSequence(n, p, k, i + 1, v);

    if (i) {
        GenerateSequence(AddNum(n, p[i], k + 1), p, k, i + 1, v);
    }
    return;
}


void MainWindow::on_number_editingFinished()
{
    update();
    int n = ui->number->value();
    if (n == 1){
        ui->answer->setText("1");
        update();
        return;
    }
    ui->number->setValue(1);
    --n;

    vector<pair<int, vector<int>>> sequence;

    for (int k = 1; n / 2 >= sequence.size(); ++k) {
        vector<int> a(k + 1);
        a[k] = 1;
        vector<vector<int>> b(k + 1);
        b[0].push_back(1);
        AddZero(b[0], k + 1);
        for (int i = 0; i < k; ++i) {
            b[i + 1] = Multiply(b[i], 10, k + 1);
        }
        GenerateSequence(a, b, k, 0, sequence);
    }


    for (int i = 0; i < sequence.size(); ++i)
        std::reverse(sequence[i].second.data(), sequence[i].second.data() + sequence[i].second.size());

    std::sort(sequence.data(), sequence.data() + sequence.size());
    --n;
    vector<int> w = sequence[n / 2].second;
    std::reverse(w.data(), w.data() + w.size());

    if (n % 2) {
        w[0] ^= 1;
    }
    QString answer;
    for (int k = sequence[n / 2].first; k >= 0; --k) {
        answer += QString::number(w[k] & 1);
    }

    ui->answer->setText(answer);
    update();
}

