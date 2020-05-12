#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    x();
    for(int i = 0; i < 9; ++i)
    for(int j = 0; j < 9 ; ++j){
    cell[i][j] = new QTextBrowser;
    cell[i][j]->setPlainText(QString::number(sudoku[0]->firstStep(i,j)));
    ui->layout->addWidget(cell[i][j],i,j);
    }


    for(auto iter = sudoku[0]->sequence.begin(); iter != sudoku[0]->sequence.end(); ++iter){
    cell[iter->first][iter->second] = new QTextBrowser;
    cell[iter->first][iter->second]->setPlainText(QString::number(sudoku[0]->sudoku[iter->first][iter->second].value));
    ui->layout->addWidget(cell[iter->first][iter->second],iter->first,iter->second);

    }

    for(int i = 0; i < 9; ++i)
    for(int j = 0; j < 9 ; ++j){
    cell[i][j] = new QTextBrowser;
    cell[i][j]->setPlainText(QString::number(sudoku[1]->firstStep(i,j)));
    ui->layout_2->addWidget(cell[i][j],i,j);
    }


    for(auto iter = sudoku[0]->sequence.begin(); iter != sudoku[0]->sequence.end(); ++iter){
    cell[iter->first][iter->second] = new QTextBrowser;
    cell[iter->first][iter->second]->setPlainText(QString::number(sudoku[1]->sudoku[iter->first][iter->second].value));
    ui->layout_2->addWidget(cell[iter->first][iter->second],iter->first,iter->second);

    }

    for(int i = 0; i < 9; ++i)
    for(int j = 0; j < 9 ; ++j){
    cell[i][j] = new QTextBrowser;
    cell[i][j]->setPlainText(QString::number(sudoku[2]->firstStep(i,j)));
    ui->layout_3->addWidget(cell[i][j],i,j);
    }


    for(auto iter = sudoku[0]->sequence.begin(); iter != sudoku[0]->sequence.end(); ++iter){
    cell[iter->first][iter->second] = new QTextBrowser;
    cell[iter->first][iter->second]->setPlainText(QString::number(sudoku[2]->sudoku[iter->first][iter->second].value));
    ui->layout_3->addWidget(cell[iter->first][iter->second],iter->first,iter->second);

    }

    for(int i = 0; i < 9; ++i)
    for(int j = 0; j < 9 ; ++j){
    cell[i][j] = new QTextBrowser;
    cell[i][j]->setPlainText(QString::number(sudoku[3]->firstStep(i,j)));
    ui->layout_4->addWidget(cell[i][j],i,j);
    }


    for(auto iter = sudoku[0]->sequence.begin(); iter != sudoku[0]->sequence.end(); ++iter){
    cell[iter->first][iter->second] = new QTextBrowser;
    cell[iter->first][iter->second]->setPlainText(QString::number(sudoku[3]->sudoku[iter->first][iter->second].value));
    ui->layout_4->addWidget(cell[iter->first][iter->second],iter->first,iter->second);

    }

    for(int i = 0; i < 9; ++i)
    for(int j = 0; j < 9 ; ++j){
    cell[i][j] = new QTextBrowser;
    cell[i][j]->setPlainText(QString::number(sudoku[4]->firstStep(i,j)));
    ui->layout_5->addWidget(cell[i][j],i,j);
    }


    for(auto iter = sudoku[0]->sequence.begin(); iter != sudoku[0]->sequence.end(); ++iter){
    cell[iter->first][iter->second] = new QTextBrowser;
    cell[iter->first][iter->second]->setPlainText(QString::number(sudoku[4]->sudoku[iter->first][iter->second].value));
    ui->layout_5->addWidget(cell[iter->first][iter->second],iter->first,iter->second);

    }

    for(int i = 0; i < 9; ++i)
    for(int j = 0; j < 9 ; ++j){
    cell[i][j] = new QTextBrowser;
    cell[i][j]->setPlainText(QString::number(sudoku[5]->firstStep(i,j)));
    ui->layout_6->addWidget(cell[i][j],i,j);
    }


    for(auto iter = sudoku[0]->sequence.begin(); iter != sudoku[0]->sequence.end(); ++iter){
    cell[iter->first][iter->second] = new QTextBrowser;
    cell[iter->first][iter->second]->setPlainText(QString::number(sudoku[5]->sudoku[iter->first][iter->second].value));
    ui->layout_6->addWidget(cell[iter->first][iter->second],iter->first,iter->second);

    }

    for(int i = 0; i < 9; ++i)
    for(int j = 0; j < 9 ; ++j){
        cell[i][j] = new QTextBrowser;
        cell[i][j]->setPlainText(QString::number(sudoku[6]->firstStep(i,j)));
        ui->layout_7->addWidget(cell[i][j],i,j);
    }


    for(auto iter = sudoku[0]->sequence.begin(); iter != sudoku[0]->sequence.end(); ++iter){
        cell[iter->first][iter->second] = new QTextBrowser;
        cell[iter->first][iter->second]->setPlainText(QString::number(sudoku[6]->sudoku[iter->first][iter->second].value));
        ui->layout_7->addWidget(cell[iter->first][iter->second],iter->first,iter->second);

    }

 //   cell[0][1] = new QTextBrowser;
//    cell[0][1]->setPlainText(QString::number(sudoku[0]->sudoku[0][1].value));
 //   ui->layout->addWidget(cell[0][1],0,1);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::a(){


}

void MainWindow::x(){

    for(int i = 0 ; i < 7 ; i++)
    {
        ifstream file("C:\\Users\\faruk\\Desktop\\sudoku.txt");
        sudoku[i] = new SudokuBoard(file,i);
    }
    for(int i = 0 ; i < 7 ; i++)
    {
      //  auto start = std::chrono::steady_clock::now();
        t[i] = new std::thread(&SudokuBoard::solveSudoku,sudoku[i]);
     //   auto end = std::chrono::steady_clock::now();
    //    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
     //   std::cout << "It took me " << elapsed.count() << " milliseconds." << std::endl;
    }
    // ui->cell0->setPlainText( QString::number(sudoku[0]->sudoku[0][3].value));

}

void MainWindow::delay(){
    const auto time = QTime::currentTime().addSecs(1);
    while(QTime::currentTime() < time){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}
