#include "swetaa_notepad_assign_212218104169.h"
#include "ui_swetaa_notepad_assign_212218104169.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QFileDialog>
#include<QFontDialog>
#include<QPrinter>
#include<QPrintDialog>
#include<QColorDialog>
#include<QColor>

swetaa_notepad_assign_212218104169::swetaa_notepad_assign_212218104169(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::swetaa_notepad_assign_212218104169)
{
    ui->setupUi(this);
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

swetaa_notepad_assign_212218104169::~swetaa_notepad_assign_212218104169()
{
    delete ui;
}


void swetaa_notepad_assign_212218104169::on_actioncut_triggered()
{
      ui->textEdit->cut();
}

void swetaa_notepad_assign_212218104169::on_actioncopy_triggered()
{
       ui->textEdit->copy();
}

void swetaa_notepad_assign_212218104169::on_actionpaste_triggered()
{
       ui->textEdit->paste();
}

void swetaa_notepad_assign_212218104169::on_actionnew_triggered()
{
    file_path=" ";
       ui->textEdit->setText("");
}

void swetaa_notepad_assign_212218104169::on_actionopen_triggered()
{
    QString file_name=QFileDialog::getOpenFileName(this,"open the file");
       QFile file(file_name);
       file_path=file_name;
       if(!file.open(QFile::ReadOnly|QFile::Text))
       {
           QMessageBox::warning (this,"..","file not open");
           return;
       }
       QTextStream in(&file);
       QString text=in.readAll();
       ui->textEdit->setText(text);
       file.close();
}

void swetaa_notepad_assign_212218104169::on_actionsave_triggered()
{
    QFile file(file_path);
      if(!file.open(QFile::WriteOnly|QFile::Text))
      {
          QMessageBox::warning (this,"..","file not open");
          return;
      }
      QTextStream out(&file);
      QString text=ui->textEdit->toPlainText();
      out<<text;
      file.flush();
      file.close();

}

void swetaa_notepad_assign_212218104169::on_actionsave_as_triggered()
{

    QString file_name=QFileDialog::getSaveFileName(this,"open the file");
    QFile file(file_name);
    file_path=file_name;
    if(!file.open(QFile::WriteOnly|QFile::Text))
    {
        QMessageBox::warning (this,"..","file not open");
        return;
    }
    QTextStream out(&file);
    QString text=ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}

void swetaa_notepad_assign_212218104169::on_actionprint_triggered()
{

    QPrinter printer;
    printer.setPrinterName("desired printer name");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec() == QDialog::Rejected) return;
    ui->textEdit->print(&printer);


}

void swetaa_notepad_assign_212218104169::on_actionquit_triggered()
{
      QApplication::quit();
}

void swetaa_notepad_assign_212218104169::on_actionselect_font_triggered()
{
    bool fontSelected;
       QFont font=QFontDialog::getFont(&fontSelected,this);
       if(fontSelected)
       {
           ui->textEdit->setFont(font);

       }
}

void swetaa_notepad_assign_212218104169::on_actionbold_triggered()
{
    QTextCharFormat format;
       format.setFontWeight(QFont::Bold);

      QTextCursor cursor = ui->textEdit->textCursor();
      cursor.mergeCharFormat(format);
}

void swetaa_notepad_assign_212218104169::on_actionitalic_triggered()
{
     ui->textEdit->setFontItalic(true);
}

void swetaa_notepad_assign_212218104169::on_actionunderline_triggered()
{
     ui->textEdit->setFontUnderline(true);
}

void swetaa_notepad_assign_212218104169::on_actionfont_color_triggered()
{
    QTextCursor cursor( ui->textEdit->textCursor() );

       QTextCharFormat format;

       format.setForeground( QBrush( QColor( "yellow" ) ) );
       cursor.setCharFormat( format );
   }


void swetaa_notepad_assign_212218104169::on_actionselect_font_background_color_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"choose color");
       if(color.isValid()){
           ui->textEdit->setTextBackgroundColor(color);
       }
}

void swetaa_notepad_assign_212218104169::on_actionundo_triggered()
{
       ui->textEdit->undo();
}

void swetaa_notepad_assign_212218104169::on_actionredo_triggered()
{
       ui->textEdit->redo();
}
