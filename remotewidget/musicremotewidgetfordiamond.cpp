#include "musicremotewidgetfordiamond.h"

MusicRemoteWidgetForDiamond::MusicRemoteWidgetForDiamond(QWidget *parent)
    : MusicRemoteWidget(parent)
{
    setGeometry(200,200,100,100);
    setAttribute(Qt::WA_TranslucentBackground);
    QRect deskRect = QApplication::desktop()->availableGeometry();
    move( deskRect.width() - width() - 150, height() + 70);

    const QString MusicRemoteControlButton = "\
           QPushButton{background:transparent;border-none;}\
           QPushButton::hover{image:url(:/image/shadow);}";
    m_PreSongButton->setStyleSheet(MusicRemoteControlButton);
    m_NextSongButton->setStyleSheet(MusicRemoteControlButton);
    m_PlayButton->setStyleSheet(MusicRemoteControlButton);
    m_SettingButton->setStyleSheet(MusicRemoteControlButton);
    m_showMainWindow->setIconSize(QSize(40,40));
    m_mainWidget->setStyleSheet("#mainWidget{background:transparent}");

    QGridLayout* grid = new QGridLayout(this);
    m_PreSongButton->setFixedSize(30,30);
    m_NextSongButton->setFixedSize(30,30);
    m_PlayButton->setFixedSize(30,30);
    m_SettingButton->setFixedSize(30,30);
    m_mainWidget->setFixedSize(70,70);
    grid->addWidget(m_PlayButton,0,1,Qt::AlignCenter);
    grid->addWidget(m_PreSongButton,1,0,Qt::AlignCenter);
    grid->addWidget(m_NextSongButton,1,2,Qt::AlignCenter);
    grid->addWidget(m_SettingButton,2,1,Qt::AlignCenter);
    grid->addWidget(m_mainWidget,1,1,Qt::AlignCenter);

    QVBoxLayout *mainWidgetLayout = new QVBoxLayout(m_mainWidget);
    mainWidgetLayout->setContentsMargins(0,0,0,0);
    mainWidgetLayout->setSpacing(0);
    mainWidgetLayout->addWidget(m_showMainWindow);
    mainWidgetLayout->setAlignment(m_showMainWindow,Qt::AlignCenter);
    mainWidgetLayout->addWidget(m_volumnWidget);
    m_showMainWindow->setFixedSize(30,40);

}

void MusicRemoteWidgetForDiamond::paintEvent(QPaintEvent* event)
{
    MusicRemoteWidget::paintEvent(event);
    QPainter painter(this);
    QPolygon pts;
    pts.setPoints(4, 8,80 , 80,8, 154,81, 80,154);
    QPainterPath path;
    path.addPolygon(pts);
    painter.fillPath(path,QBrush(QColor(0,0,0,125)));
    painter.end();
}
