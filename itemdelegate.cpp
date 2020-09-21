#include "itemdelegate.h"

#include <QPainter>
#include <QDebug>
#include <QApplication>

ItemDelegate::ItemDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void ItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionViewItem mOption = option;
    initStyleOption(&mOption, index);

    QStyledItemDelegate::paint(painter, mOption, index);

    QFontMetrics metrics = painter->fontMetrics();

    if (mOption.type & Qt::ForegroundRole) {
        QString strText = index.data().toString();
        if (strText.left(3) == QString("收件箱")) {
            if (!strText.mid(3).isEmpty()) {
                int unFindstrWid = metrics.horizontalAdvance(strText.left(3));

                painter->save();
                painter->setFont(QApplication::font(mOption.widget));

                painter->setPen(Qt::red);
                painter->setRenderHint(QPainter::Antialiasing, true);
                painter->drawText(mOption.rect.adjusted(unFindstrWid + 3, 1, metrics.horizontalAdvance(strText) - mOption.rect.width() + 3, 1), strText.mid(3));
                painter->restore();
            }
        }
    }
}
