#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createLanguageMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void switchTranslator(QTranslator& translator, const QString& filename) {
    // remove the old translator
    qApp->removeTranslator(&translator);

    // load the new translator
    QString path = QApplication::applicationDirPath();
    path.append("/languages/");
    if(translator.load(path + filename)) //Here Path and Filename has to be entered because the system didn't find the QM Files else
        qApp->installTranslator(&translator);
}

void MainWindow::loadLanguage(const QString &rLanguage)
{
    if(m_currLang != rLanguage) {
        m_currLang = rLanguage;
        QLocale locale = QLocale(m_currLang);
        QLocale::setDefault(locale);
        switchTranslator(m_translator, QString("TranslationExample_%1.qm").arg(rLanguage));
        switchTranslator(m_translatorQt, QString("qt_%1.qm").arg(rLanguage));
        // QString languageName = QLocale::languageToString(locale.language());
        ui->statusbar->showMessage(tr("Current Language changed to %1").arg(locale.nativeLanguageName()));
    }
}

void MainWindow::createLanguageMenu()
{
    QActionGroup *langGroup = new QActionGroup(ui->menuLanguage);
    langGroup->setExclusive(true);

    connect(langGroup, &QActionGroup::triggered, this, &MainWindow::slotLanguageChanged);

    // format system language
    QString defaultLocale = QLocale::system().name(); // "de_DE"
    defaultLocale.truncate(defaultLocale.lastIndexOf('_')); // "de"

    m_langPath = QApplication::applicationDirPath();
    m_langPath.append("/languages");
    QDir dir(m_langPath);
    QStringList fileNames = dir.entryList(QStringList("TranslationExample_*.qm"));

    for(int i = 0; i < fileNames.size(); i++)
    {
        // get locale extracted by filename
        QString locale;
        locale = fileNames[i]; // "TranslationExample_de.qm"
        locale.truncate(locale.lastIndexOf('.')); // "TranslationExample_de"
        locale.remove(0, locale.lastIndexOf('_') + 1); // "de
        qInfo() << locale;
        QString lang = QLocale::languageToString(QLocale(locale).language());
        qInfo() << lang;
        QIcon ico(QString("%1/%2.png").arg(m_langPath).arg(locale));

        QAction *action = new QAction(ico, lang, this);
        action->setCheckable(true);
        action->setData(locale);
        ui->menuLanguage->addAction(action);
        langGroup->addAction(action);
        // set default translators and language checked
        if (defaultLocale == locale) {
            action->setChecked(true);
        }
    }
}

void MainWindow::changeEvent(QEvent* event) {
    if(0 != event) {
        switch(event->type()) {
        // this event is send if a translator is loaded
        case QEvent::LanguageChange:
            ui->retranslateUi(this);
            break;

            // this event is send, if the system, language changes
        case QEvent::LocaleChange:
        {
            QString locale = QLocale::system().name();
            locale.truncate(locale.lastIndexOf('_'));
            loadLanguage(locale);
        }
        case QEvent::None:
        case QEvent::Timer:
        case QEvent::MouseButtonPress:
        case QEvent::MouseButtonRelease:
        case QEvent::MouseButtonDblClick:
        case QEvent::MouseMove:
        case QEvent::KeyPress:
        case QEvent::KeyRelease:
        case QEvent::FocusIn:
        case QEvent::FocusOut:
        case QEvent::FocusAboutToChange:
        case QEvent::Enter:
        case QEvent::Leave:
        case QEvent::Paint:
        case QEvent::Move:
        case QEvent::Resize:
        case QEvent::Create:
        case QEvent::Destroy:
        case QEvent::Show:
        case QEvent::Hide:
        case QEvent::Close:
        case QEvent::Quit:
        case QEvent::ParentChange:
        case QEvent::ParentAboutToChange:
        case QEvent::ThreadChange:
        case QEvent::WindowActivate:
        case QEvent::WindowDeactivate:
        case QEvent::ShowToParent:
        case QEvent::HideToParent:
        case QEvent::Wheel:
        case QEvent::WindowTitleChange:
        case QEvent::WindowIconChange:
        case QEvent::ApplicationWindowIconChange:
        case QEvent::ApplicationFontChange:
        case QEvent::ApplicationLayoutDirectionChange:
        case QEvent::ApplicationPaletteChange:
        case QEvent::PaletteChange:
        case QEvent::Clipboard:
        case QEvent::Speech:
        case QEvent::MetaCall:
        case QEvent::SockAct:
        case QEvent::WinEventAct:
        case QEvent::DeferredDelete:
        case QEvent::DragEnter:
        case QEvent::DragMove:
        case QEvent::DragLeave:
        case QEvent::Drop:
        case QEvent::DragResponse:
        case QEvent::ChildAdded:
        case QEvent::ChildPolished:
        case QEvent::ChildRemoved:
        case QEvent::ShowWindowRequest:
        case QEvent::PolishRequest:
        case QEvent::Polish:
        case QEvent::LayoutRequest:
        case QEvent::UpdateRequest:
        case QEvent::UpdateLater:
        case QEvent::EmbeddingControl:
        case QEvent::ActivateControl:
        case QEvent::DeactivateControl:
        case QEvent::ContextMenu:
        case QEvent::InputMethod:
        case QEvent::TabletMove:
        case QEvent::LayoutDirectionChange:
        case QEvent::Style:
        case QEvent::TabletPress:
        case QEvent::TabletRelease:
        case QEvent::OkRequest:
        case QEvent::HelpRequest:
        case QEvent::IconDrag:
        case QEvent::FontChange:
        case QEvent::EnabledChange:
        case QEvent::ActivationChange:
        case QEvent::StyleChange:
        case QEvent::IconTextChange:
        case QEvent::ModifiedChange:
        case QEvent::MouseTrackingChange:
        case QEvent::WindowBlocked:
        case QEvent::WindowUnblocked:
        case QEvent::WindowStateChange:
        case QEvent::ReadOnlyChange:
        case QEvent::ToolTip:
        case QEvent::WhatsThis:
        case QEvent::StatusTip:
        case QEvent::ActionChanged:
        case QEvent::ActionAdded:
        case QEvent::ActionRemoved:
        case QEvent::FileOpen:
        case QEvent::Shortcut:
        case QEvent::ShortcutOverride:
        case QEvent::WhatsThisClicked:
        case QEvent::ToolBarChange:
        case QEvent::ApplicationActivate:
        case QEvent::ApplicationDeactivate:
        case QEvent::QueryWhatsThis:
        case QEvent::EnterWhatsThisMode:
        case QEvent::LeaveWhatsThisMode:
        case QEvent::ZOrderChange:
        case QEvent::HoverEnter:
        case QEvent::HoverLeave:
        case QEvent::HoverMove:
        case QEvent::AcceptDropsChange:
        case QEvent::ZeroTimerEvent:
        case QEvent::GraphicsSceneMouseMove:
        case QEvent::GraphicsSceneMousePress:
        case QEvent::GraphicsSceneMouseRelease:
        case QEvent::GraphicsSceneMouseDoubleClick:
        case QEvent::GraphicsSceneContextMenu:
        case QEvent::GraphicsSceneHoverEnter:
        case QEvent::GraphicsSceneHoverMove:
        case QEvent::GraphicsSceneHoverLeave:
        case QEvent::GraphicsSceneHelp:
        case QEvent::GraphicsSceneDragEnter:
        case QEvent::GraphicsSceneDragMove:
        case QEvent::GraphicsSceneDragLeave:
        case QEvent::GraphicsSceneDrop:
        case QEvent::GraphicsSceneWheel:
        case QEvent::GraphicsSceneLeave:
        case QEvent::KeyboardLayoutChange:
        case QEvent::DynamicPropertyChange:
        case QEvent::TabletEnterProximity:
        case QEvent::TabletLeaveProximity:
        case QEvent::NonClientAreaMouseMove:
        case QEvent::NonClientAreaMouseButtonPress:
        case QEvent::NonClientAreaMouseButtonRelease:
        case QEvent::NonClientAreaMouseButtonDblClick:
        case QEvent::MacSizeChange:
        case QEvent::ContentsRectChange:
        case QEvent::MacGLWindowChange:
        case QEvent::FutureCallOut:
        case QEvent::GraphicsSceneResize:
        case QEvent::GraphicsSceneMove:
        case QEvent::CursorChange:
        case QEvent::ToolTipChange:
        case QEvent::NetworkReplyUpdated:
        case QEvent::GrabMouse:
        case QEvent::UngrabMouse:
        case QEvent::GrabKeyboard:
        case QEvent::UngrabKeyboard:
        case QEvent::StateMachineSignal:
        case QEvent::StateMachineWrapped:
        case QEvent::TouchBegin:
        case QEvent::TouchUpdate:
        case QEvent::TouchEnd:
        case QEvent::NativeGesture:
        case QEvent::RequestSoftwareInputPanel:
        case QEvent::CloseSoftwareInputPanel:
        case QEvent::WinIdChange:
        case QEvent::Gesture:
        case QEvent::GestureOverride:
        case QEvent::ScrollPrepare:
        case QEvent::Scroll:
        case QEvent::Expose:
        case QEvent::InputMethodQuery:
        case QEvent::OrientationChange:
        case QEvent::TouchCancel:
        case QEvent::ThemeChange:
        case QEvent::SockClose:
        case QEvent::PlatformPanel:
        case QEvent::StyleAnimationUpdate:
        case QEvent::ApplicationStateChange:
        case QEvent::WindowChangeInternal:
        case QEvent::ScreenChangeInternal:
        case QEvent::PlatformSurface:
        case QEvent::Pointer:
        case QEvent::TabletTrackingChange:
        case QEvent::WindowAboutToChangeInternal:
        case QEvent::DevicePixelRatioChange:
        case QEvent::User:
        case QEvent::MaxUser:
            break;
        }
    }
    QMainWindow::changeEvent(event);
}

void MainWindow::slotLanguageChanged(QAction *action)
{
    if(0 != action) {
        // load the language dependant on the action content
        loadLanguage(action->data().toString());
        setWindowIcon(action->icon());
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::information(this, "Closing", "Do you wanna close it");
}










