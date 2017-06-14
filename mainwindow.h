#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Btn_0_clicked();

    void on_Btn_1_clicked();

    void on_Btn_2_clicked();

    void on_Btn_3_clicked();

    void on_Btn_4_clicked();

    void on_Btn_5_clicked();

    void on_Btn_6_clicked();

    void on_Btn_7_clicked();

    void on_Btn_8_clicked();

    void on_Btn_9_clicked();

    void on_Btn_Dot_clicked();



    void on_Btn_Add_clicked();

    void on_Btn_Equ_clicked();

    void on_Btn_Miv_clicked();

    void on_Btn_Mul_clicked();

    void on_Btn_Div_clicked();

    void on_Btn_Ret_clicked();

    void on_Btn_Del_clicked();
    
private:
    Ui::MainWindow *ui;

    //用于计算的变量
    double Fir_Num;
    double Sec_Num;
    int Calculate;

    //显示变量
    QString LCD_String;

    //判断变量
    bool Num_Seq = true;
    bool Num_0_Input = true;
    bool Dot_Input = true;

    //判断函数
    bool Judge_num_Input()
    {
        if(LCD_String.size()>=8)
            return false;
        else
            return true;
    }

    bool Judge_Zero_Input()
    {
        if(LCD_String.size() == 1 && LCD_String.left(1) == "0")
        {
            return false;
        }
        else
            return true;
    }

    bool Judge_Dot_Input()
    {
        if(LCD_String.size() == 0)
            return false;
        if(LCD_String.size() >0 && LCD_String.size()<7)
        {
            if(Dot_Input == true)
                return true;
            if(Dot_Input == false)
                return false;
        }
    }

    void SetNum(QString Number);

};

#endif // MAINWINDOW_H
