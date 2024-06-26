#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QLabel"
#include "QStandardItemModel"

void addNodesToModel(QStandardItem* parentItem, Node* currentNode) {
    if(currentNode == nullptr)
        return;

    QStandardItem* item = new QStandardItem(currentNode->getKey());
    parentItem->appendRow(item);

    if (currentNode->getLeft() != nullptr)
        addNodesToModel(item, currentNode->getLeft());

    if (currentNode->getRight() != nullptr)
        addNodesToModel(item, currentNode->getRight());
}

void Tree::goTree(Node* currentNode){
    if(currentNode == nullptr)
        return;



    if (currentNode->getLeft() != nullptr)
        goTree(currentNode->getLeft());

    if (currentNode->getRight() != nullptr)
        goTree(currentNode->getRight());
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);

    tree = new Tree();
    tree->addNode(new Node("four", 4), tree->getRoot());
    tree->addNode(new Node("five", 5), tree->getRoot());
    tree->addNode(new Node("two", 2), tree->getRoot());
    tree->addNode(new Node("seven", 7), tree->getRoot());
    tree->addNode(new Node("three", 3), tree->getRoot());
    tree->addNode(new Node("nine", 9), tree->getRoot());
    tree->addNode(new Node("twelve", 12), tree->getRoot());
    tree->addNode(new Node("eighteen", 18), tree->getRoot());
    tree->addNode(new Node("forty four",44), tree->getRoot());
    tree->addNode(new Node("one", 1), tree->getRoot());


    QStandardItemModel* model = new QStandardItemModel();
    QStandardItem* rootItem = model->invisibleRootItem();

    Node* root = tree->getRoot();

    int i = tree->getBalanceFactor(root);

    tree->balance(root);

    addNodesToModel(rootItem, root);

    ui->treeView->setModel(model);
    ui->treeView->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}
