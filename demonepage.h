#ifndef DEMONEPAGE_H
#define DEMONEPAGE_H

#include <QWidget>
QT_BEGIN_NAMESPACE
namespace Ui { class DemonePage; }
QT_END_NAMESPACE
class DemonePage : public QWidget
{
    Q_OBJECT
public:
    explicit DemonePage(QWidget *parent = nullptr);

signals:

};

#endif // DEMONEPAGE_H
