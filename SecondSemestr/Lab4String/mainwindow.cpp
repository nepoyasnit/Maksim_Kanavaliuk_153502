#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

namespace mystl {
    class myStr {
    private:
        unsigned length;
        char* str = 0;
    public:
        myStr() {
            length = 0;
            str = (char*)malloc(0);
        }

        ~myStr() {
            free(str);
        }

        myStr(unsigned size) {
            length = size;
            str = (char*)malloc(length + sizeof(char));
        }

        myStr(const char s[]) {
            int l;
            for(l = 0; s[l]; ++l) {}
            length = l;
            resize(length);
            for(int i = 0; i < l; ++i) {
                str[i] = s[i];
            }
        }

        myStr(const char c) {
            int length = 2;
            resize(length);
            str[0] = c;
            str[1] = '\0';
        }

        myStr(const myStr& s) {
            str = (char*)malloc(s.size() + sizeof(char));
            length = s.size();
            for(unsigned i = 0; i < length; ++i) {
                str[i] = s[i];
            }
        }

        char& operator[](unsigned i) {
            return str[i];
        }

        char* data(){
            return str;
        }

        char& operator[](unsigned i) const {
            return str[i];
        }

        myStr& operator=(const char oth[]) {
            int l;
            for(l = 0; oth[l]; ++l) {}
            length = l;
            resize(length);
            for(int i = 0; i < l; ++i) {
                str[i] = oth[i];
            }
            return *this;
        }

        myStr& operator=(myStr oth) {
            str = nullptr;
            resize(oth.size());
            for(unsigned i = 0; i < length; ++i) {
                str[i] = oth[i];
            }
            return *this;
        }

        unsigned size() const {
            return length;
        }

        void reverse() {
            for(unsigned i = 0; i < length / 2; ++i) {
                char tmp = str[i];
                unsigned l = length - i - 1;
                str[i] = str[l];
                str[l] = tmp;
            }
            return;
        }

        unsigned count(char a) {
            unsigned counter = 0;
            for(unsigned i = 0; i < length; ++i) {
                if(str[i] == a)
                    ++counter;
            }
            return counter;
        }

        void resize(unsigned n_size) {
            char* tmp = (char*)realloc(str, n_size * sizeof(char));
            if(tmp != nullptr) {
                str = tmp;
                length = n_size;
            }
        }

        int find(char c) {
            for(unsigned i = 0; i < length; ++i) {
                if(str[i] == c)
                    return i;
            }
            return -1;
        }

        int find(unsigned start, unsigned end, char c) {
            if(start >= length || end == 0)
                return -1;
            for(unsigned i = start; i < end; ++i) {
                if(str[i] == c)
                    return i;
            }
            return -1;
        }

        int find(unsigned start, char c) {
            if(start >= length)
                    return -1;
            for(unsigned i = start; i < length; ++i) {
                if(str[i] == c)
                    return i;
            }
            return -1;
        }

        int find(myStr& s){
            if(s.size() > length) {
                return -1;
            }

            unsigned i = 0;
            bool isEq = false;
            unsigned pos;
            for(; i < size(); ++i) {
                if(str[i] != s[0])
                    continue;
                pos = i + 1;
                isEq = true;
                for(unsigned j = 1; j < s.size(); ++j, ++pos) {
                    if(str[pos] != s[j]) {
                        isEq = false;
                        break;
                    }
                }
                if(isEq)
                    return i;
            }
            return -1;
        }

        void insert(char a, unsigned pos) {
            resize(length + 1);
            for(unsigned i = length - 1; i > pos; --i) {
                str[i] = str[i-1];
            }
            str[pos] = a;
        }

        void erase(unsigned start, unsigned end) {
            if(!(length - (end - start))) {
                resize(0);
                str = nullptr;
                return;
            }
            unsigned l = 0;
            for(unsigned i = start; i < end; ++i) {
                str[i] = str[end + l];
            }
            for(unsigned i = end; i < length - l; ++i) {
                str[i] = str[i + l];
            }
            resize(length - (end - start));
        }

        bool is_combination(myStr s) {
            for(unsigned i = 0; i < length; ++i) {
                if(!s.count(str[i])) {
                    return false;
                }
            }
            return true;
        }

        bool is_palindrom() {
            for(unsigned i = 0; i < length/2; ++i) {
                if(str[i] != str[length - i - 1])
                    return false;
            }
            return true;
        }
    };

    std::ostream& operator<<(std::ostream& out, myStr s) {
        for(unsigned i = 0; i < s.size(); ++i) {
            out << s[i];
        }
        return out;
    }

    std::istream& operator>>(std::istream& in, myStr& s) {
        char c[100];
        in >> c;
        s = c;
        return in;
    }

    myStr operator+(myStr& s1, char c) {
        myStr sum(s1.size() + 1);
        for(unsigned i = 0; i < s1.size(); ++i) {
            sum[i] = s1[i];
        }
        sum[s1.size()] = c;
        return sum;
    }


    void operator+=(myStr& s1, char c) {
        s1.resize(s1.size() + 2);
        s1[s1.size() - 2] = c;
        s1[s1.size() - 1] = '\0';
    }

    myStr& operator+=(myStr& a, myStr& b) {
        unsigned a_size = a.size();
        a.resize(a_size + b.size());
        for(unsigned i = a_size; i < a.size(); ++i) {
            a[i] = b[i - a_size];
        }
        return a;
    }

    bool operator==(const myStr& a, const myStr& b) {
        if(a.size() != b.size())
            return false;
        for(unsigned i = 0; i < a.size(); ++i) {
            if(a[i] != b[i])
                return false;
        }
        return true;
    }

    void* memcpy_n(void* s1, const void* s2, unsigned n) {
        char* a = (char*)s1;
        char* b = (char*)s2;
        while(n--) {
            *a = *b;
            ++a;
            ++b;
         }
        return s1;
    }

    void* memmove_n(void* s1, const void* s2, unsigned n) {
        void *ret = s1;
        if(s1 <= s2  || (char*)s1 >= ((char*)s2 + n)) {
            while(n--) {
                *(char*)s1 = *(char*)s2;
                s1 = (char*)s1 + 1;
                s2 = (char*)s2 + 1;
            }
        }
        else {
            s1 = (char*)s1 + n - 1;
            s2 = (char*)s2 + n - 1;
            while(n--) {
                *(char*)s1 = *(char*)s2;
                s1 = (char*)s1 - 1;
                s2 = (char*)s2 - 1;
            }
        }
        return ret;
    }

    char* strcpy_n(char* s1, const char* s2) {
        unsigned length = 0;
        for(; s2[length]; ++length) {}
        s1 = new char[length + 1];
        for(unsigned i = 0; i < length; ++i) {
            s1[i] = s2[i];
        }
        s1[length] = '\0';
        return s1;
    }

    char* strncpy_n(char* s1, const char* s2, unsigned n) {
        unsigned length = 0;
        for(; s2[length]; ++length) {}
        if(n > length)
            n = length - 1;
        for(unsigned i = 0; i < n; ++i)
            s1[i] = s2[i];
        s1[n] = '\0';
        return s1;
    }

    char* strcat(char* s1, const char* s2) {
        int length = 0;
        for(unsigned i = 0; s1[i]; ++i, ++length) {}
        for(unsigned i = 0; s2[i]; ++i, ++length) {}
        char* s = new char[length];
        for(unsigned i = 0; s1[i]; ++i) {
            s[i] = s1[i];
            length = i;
        }
        for(unsigned i = length + 1, j = 0; s2[j]; ++i, ++j) {
            s[i] = s2[j];
        }
        return s;
    }

    char* strncat(char* s1, const char* s2, unsigned n) {
        unsigned length = 0;
        for(unsigned i = 0; s1[i]; ++i, ++length){}
        for(unsigned i = 0; s2[i]; ++i, ++length) {}
        char* s;
        if(length < n)
            s = new char[length];
        else
            s = new char[n];

        for(unsigned i = 0; s1[i]; ++i) {
            s[i] = s1[i];
            length = i;
        }
        for(unsigned i = length + 1, j = 0; s2[j] && j < n; ++i, ++j) {
            s[i] = s2[j];
            length = i;
        }
        s[length + 1] = '\0';
        return s;
    }
}

mystl::myStr str = "";

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

void MainWindow::on_reverseButton_clicked()
{
    str.reverse();
}


void MainWindow::on_sizeButton_clicked()
{
    ui->showText->append("Size of the string is " + QString::number(str.size()));
}



void MainWindow::on_plusButton_clicked()
{
    mystl::myStr tmp = ui->inputEdit->text().toStdString().data();
    str += tmp;
    dushnila();
}

void MainWindow::on_countButton_clicked()
{
    mystl::myStr a = ui->inputEdit->text().toStdString().data();
    char tmp = a[0];
    ui->showText->append("Count: " + QString::number(str.count(tmp)));
}


void MainWindow::on_isPalButton_clicked()
{
   if(str.is_palindrom())
       ui->showText->append("String is a palindrom");
   else
       ui->showText->append("String isn't a palindrom");
}


void MainWindow::on_findButton_clicked()
{
    mystl::myStr a = ui->inputEdit->text().toStdString().data();
    char tmp = a[0];
    ui->showText->append("Find: " + QString::number(str.find(tmp)));
}

void MainWindow::on_showButton_clicked()
{
    ui->showText->setText(str.data());
}

void MainWindow::dushnila() {
    bool isEmpty = str.size() == 0;
    ui->countButton->setDisabled(isEmpty);
    ui->findButton->setDisabled(isEmpty);
    ui->reverseButton->setDisabled(isEmpty);
}
