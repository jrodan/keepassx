/*
 *  Copyright (C) 2012 Felix Geyer <debfx@fobos.de>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 or (at your option)
 *  version 3 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef KEEPASSX_ENTRYATTRIBUTESMODEL_H
#define KEEPASSX_ENTRYATTRIBUTESMODEL_H

#include <QtCore/QAbstractTableModel>

class EntryAttributes;

class EntryAttributesModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit EntryAttributesModel(QObject* parent = 0);
    void setEntryAttributes(EntryAttributes* entryAttributes);
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

private Q_SLOTS:
    void attributeChange(QString key);
    void attributeAboutToAdd(QString key);
    void attributeAdd();
    void attributeAboutToRemove(QString key);
    void attributeRemove();
    void aboutToReset();
    void reset();

private:
    void updateAttributes();

    EntryAttributes* m_entryAttributes;
    QList<QString> m_attributes;
};

#endif // KEEPASSX_ENTRYATTRIBUTESMODEL_H