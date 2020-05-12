#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextBrowser>
#include <iostream>
#include <thread>
#include <fstream>
#include "cell.h"
#include "sudokuboard.h"
#include <vector>
#include <thread>
#include <time.h>
#include <chrono>
#include <random>
#include <QTime>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void a();
    QTextBrowser *cell[9][9];
    void x();
    std::thread *t[7];
    SudokuBoard *sudoku[7];
    void delay();
    ~MainWindow();

private slots:

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
