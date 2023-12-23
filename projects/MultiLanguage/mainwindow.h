#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>
#include <QActionGroup>
#include <QDir>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    // loads a language by the given language shortcut (e.g. de, en)
    void loadLanguage(const QString& rLanguage);

    // creates the language menu dynamically from the content of m_langPath
    void createLanguageMenu(void);
    QTranslator m_translator; // contains the translations for this application
    QTranslator m_translatorQt; // contains the translations for qt
    QString m_currLang; // contains the currently loaded language
    QString m_langPath; // Path of language files. This is always fixed to /languages.

    // QWidget interface
protected:
    // this event is called, when a new translator is loaded or the system language is changed
    void changeEvent(QEvent *) override;

protected slots:
    // this slot is called by the language menu actions
    void slotLanguageChanged(QAction* action);

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event) override;
};
#endif // MAINWINDOW_H
