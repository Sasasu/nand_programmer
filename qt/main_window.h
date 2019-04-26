/*  Copyright (C) 2017 Bogdan Bogush <bogdan.s.bogush@gmail.com>
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 3.
 */

#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "programmer.h"
#include "buffer_table_model.h"
#include <QMainWindow>
#include <QVector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Programmer *prog;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QVector<uint8_t> buffer;
    BufferTableModel bufferTableModel;
    ChipId chipId;
    ChipDb chipDb;

    void initBufTable();
    void resetBufTable();
    void setUiStateConnected(bool isConnected);
    void setUiStateSelected(bool isSelected);
    void updateChipList();

private slots:
    void slotProgReadDeviceIdCompleted(int status);
    void slotProgReadCompleted(int status);
    void slotProgWriteCompleted(int status);
    void slotProgEraseCompleted(int status);
    void slotProgReadBadBlocksCompleted(int status);
    void slotProgSelectCompleted(int status);

public slots:
    void slotFileOpen();
    void slotFileSave();
    void slotProgConnect();
    void slotProgReadDeviceId();
    void slotProgErase();
    void slotProgRead();
    void slotProgWrite();
    void slotProgReadBadBlocks();
    void slotSelectChip(int selectedChipNum);
    void slotSettingsProgrammer();
    void slotSettingsChipDb();
};

#endif // MAIN_WINDOW_H
