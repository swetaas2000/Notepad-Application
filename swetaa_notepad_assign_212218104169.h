#ifndef SWETAA_NOTEPAD_ASSIGN_212218104169_H
#define SWETAA_NOTEPAD_ASSIGN_212218104169_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class swetaa_notepad_assign_212218104169; }
QT_END_NAMESPACE

class swetaa_notepad_assign_212218104169 : public QMainWindow
{
    Q_OBJECT

public:
    swetaa_notepad_assign_212218104169(QWidget *parent = nullptr);
    ~swetaa_notepad_assign_212218104169();

private slots:
    void on_actioncut_triggered();

    void on_actioncopy_triggered();

    void on_actionpaste_triggered();

    void on_actionnew_triggered();

    void on_actionopen_triggered();

    void on_actionsave_triggered();

    void on_actionsave_as_triggered();

    void on_actionprint_triggered();

    void on_actionquit_triggered();

    void on_actionselect_font_triggered();

    void on_actionbold_triggered();

    void on_actionitalic_triggered();

    void on_actionunderline_triggered();

    void on_actionfont_color_triggered();

    void on_actionselect_font_background_color_triggered();

    void on_actionundo_triggered();

    void on_actionredo_triggered();

private:
    Ui::swetaa_notepad_assign_212218104169 *ui;
     QString file_path;
};
#endif // SWETAA_NOTEPAD_ASSIGN_212218104169_H
