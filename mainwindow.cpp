@@ -13,12 +13,14 @@ MainWindow::MainWindow(QWidget *parent) :
    ui->setupUi(this);
    pContent = new MainContent();
    sReg = new Reg();
    db = new DataBase();

    connect(pContent, &MainContent::firstWindow, this, &MainWindow::show);
    connect(sReg, &Reg::firstWindow, this, &Reg
            ::show);
    connect(sReg, &Reg::firstWindow, this, &Reg::show);
    connect(this, SIGNAL(on_return()), ui->pushButton, SLOT(click()));
    log.clear();
    str.clear();
    //строки и так пустые
    //log.clear();
    //str.clear();

}

@@ -26,6 +28,7 @@ MainWindow::~MainWindow()
{
    delete ui;
    delete pContent;
    //можно выйти из программы не нажав кнопку 3
    delete db;
    delete sReg;
}
@@ -38,7 +41,6 @@ void MainWindow::on_pushButton_2_clicked()

void MainWindow::on_pushButton_3_clicked()
{
    db = new DataBase();
    db->show();
}

