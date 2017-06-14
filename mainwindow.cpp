#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Calculate = -1;
    ui->setupUi(this);
    ui->lcdNumber->setDigitCount(8);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Btn_0_clicked()
{
    if(Judge_num_Input() && Judge_Zero_Input())
    {
        LCD_String.append("0");
    }
    ui->lcdNumber->display(LCD_String);
}

void MainWindow::on_Btn_1_clicked()
{
   SetNum("1");
}

void MainWindow::on_Btn_2_clicked()
{
    SetNum("2");
}

void MainWindow::on_Btn_3_clicked()
{
    SetNum("3");
}
void MainWindow::on_Btn_4_clicked()
{
    SetNum("4");
}

void MainWindow::on_Btn_5_clicked()
{
    SetNum("5");
}

void MainWindow::on_Btn_6_clicked()
{
    SetNum("6");
}

void MainWindow::on_Btn_7_clicked()
{
    SetNum("7");
}

void MainWindow::on_Btn_8_clicked()
{
    SetNum("8");
}

void MainWindow::on_Btn_9_clicked()
{
    SetNum("9");
}

void MainWindow::on_Btn_Dot_clicked()
{
    if(LCD_String.size()<=0 || LCD_String.size()>=7 || Dot_Input == false)
    {
    }
    else
    {
        LCD_String.append(".");
        Dot_Input = false;
        ui->lcdNumber->display(LCD_String);
    }
}

void MainWindow::SetNum(QString Number)
{
    if(LCD_String == "0")
    {
        LCD_String.clear();
    }
    if(Judge_num_Input())
    {
        LCD_String.append(Number);
    }
    ui->lcdNumber->display(LCD_String);
}

//运算符
void MainWindow::on_Btn_Add_clicked()
{
    Fir_Num = LCD_String.toDouble();
    Calculate = 1;
    LCD_String.clear();
    Dot_Input = true;
}

void MainWindow::on_Btn_Miv_clicked()
{
    Fir_Num = LCD_String.toDouble();
    Calculate = 2;
    LCD_String.clear();
    Dot_Input = true;
}

void MainWindow::on_Btn_Mul_clicked()
{
    Fir_Num = LCD_String.toDouble();
    Calculate = 3;
    LCD_String.clear();
    Dot_Input = true;
}

void MainWindow::on_Btn_Div_clicked()
{
    Fir_Num = LCD_String.toDouble();
    Calculate = 4;
    LCD_String.clear();
    Dot_Input = true;
}

//运算符
void MainWindow::on_Btn_Equ_clicked()
{
    Sec_Num = LCD_String.toDouble();
    switch(Calculate)
    {
    case 1:
    {
        Fir_Num = Fir_Num + Sec_Num;
        ui->lcdNumber->display(Fir_Num);
        LCD_String.clear();
        break;
    }
    case 2:
    {
        Fir_Num = Fir_Num - Sec_Num;
        ui->lcdNumber->display(Fir_Num);
        LCD_String.clear();
        break;
    }
    case 3:
    {
        Fir_Num = Fir_Num * Sec_Num;
        ui->lcdNumber->display(Fir_Num);
        LCD_String.clear();
        break;
    }
    case 4:
    {
        if(Sec_Num == 0)
        {
            ui->lcdNumber->display("ERROR");break;
        }
        else
        {
            Fir_Num = Fir_Num / Sec_Num;
            ui->lcdNumber->display(Fir_Num);
            LCD_String.clear();
            break;
        }
    }
    default:
    {
        ui->lcdNumber->display(LCD_String);break;
    }
    }
}

//功能按钮
void MainWindow::on_Btn_Ret_clicked()
{
    LCD_String.clear();
    LCD_String.append("0");
    ui->lcdNumber->display(LCD_String);
    Num_Seq = true;
    Num_0_Input = true;
    Dot_Input = true;
}

void MainWindow::on_Btn_Del_clicked()
{
    LCD_String = LCD_String.left(LCD_String.size()-1);
    if(LCD_String.size() <= 0)
    {
        LCD_String.append("0");
        ui->lcdNumber->display(LCD_String);
    }
    else
    {
        ui->lcdNumber->display(LCD_String);
    }
}
