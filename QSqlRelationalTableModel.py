
import sys
from PyQt5.QtCore import QObject
from PyQt5.QtCore import Qt
from PyQt5.QtSql import QSqlTableModel, QSqlRelation, QSqlRelationalDelegate, QSqlQuery, QSqlRelationalTableModel, \
    QSqlDatabase
from PyQt5.QtWidgets import QApplication
from PyQt5.QtWidgets import QMessageBox
from PyQt5.QtWidgets import QTableView
from PyQt5.QtWidgets import qApp


def initializeModel(model):
    model.setTable("employee")
    model.setEditStrategy(QSqlTableModel.OnRowChange)
    model.setRelation(2, QSqlRelation("city", "id", "name"))
    model.setRelation(3, QSqlRelation("country", "id", "name"))
    model.setHeaderData(0, Qt.Horizontal, ("ID"))
    model.setHeaderData(1, Qt.Horizontal, ("Name"))
    model.setHeaderData(2, Qt.Horizontal, ("City"))
    model.setHeaderData(3, Qt.Horizontal, ("Country"))

    model.select()


def createView(title, model):
    view = QTableView()
    view.setModel(model)
    view.setItemDelegate(QSqlRelationalDelegate(view))
    view.setWindowTitle(title)
    return view


def createRelationalTables():
    query = QSqlQuery()
    query.exec("create table employee(id int primary key, name varchar(20), city int, country int)")
    query.exec("insert into employee values(1, 'Espen', 5000, 47)")
    query.exec("insert into employee values(2, 'Harald', 80000, 49)")
    query.exec("insert into employee values(3, 'Sam', 100, 1)")

    query.exec("create table city(id int, name varchar(20))")
    query.exec("insert into city values(100, 'San Jose')")
    query.exec("insert into city values(5000, 'Oslo')")
    query.exec("insert into city values(80000, 'Munich')")

    query.exec("create table country(id int, name varchar(20))")
    query.exec("insert into country values(1, 'USA')")
    query.exec("insert into country values(47, 'Norway')")
    query.exec("insert into country values(49, 'Germany')")


def createConnection():
    db = QSqlDatabase.addDatabase("QSQLITE");
    db.setDatabaseName("demo");
    if not db.open():
        QMessageBox.critical(0, qApp.tr("Cannot open database"),
                             qApp.tr("Unable to establish a database connection.\n"
                                     "This example needs SQLite support. Please read "
                                     "the Qt SQL driver documentation for information how "
                                     "to build it.\n\n"
                                     "Click Cancel to exit."), QMessageBox.Cancel);
        return False;

    query = QSqlQuery()
    query.exec("create table person (id int primary key, "
               "firstname varchar(20), lastname varchar(20))");
    query.exec("insert into person values(101, 'Danny', 'Young')");
    query.exec("insert into person values(102, 'Christine', 'Holand')");
    query.exec("insert into person values(103, 'Lars', 'Gordon')");
    query.exec("insert into person values(104, 'Roberto', 'Robitaille')");
    query.exec("insert into person values(105, 'Maria', 'Papadopoulos')");

    query.exec("create table items (id int primary key,"
               "imagefile int,"
               "itemtype varchar(20),"
               "description varchar(100))");
    query.exec("insert into items "
               "values(0, 0, 'Qt',"
               "'Qt is a full development framework with tools designed to "
               "streamline the creation of stunning applications and  "
               "amazing user interfaces for desktop, embedded and mobile "
               "platforms.')");
    query.exec("insert into items "
               "values(1, 1, 'Qt Quick',"
               "'Qt Quick is a collection of techniques designed to help "
               "developers create intuitive, modern-looking, and fluid "
               "user interfaces using a CSS & JavaScript like language.')");
    query.exec("insert into items "
               "values(2, 2, 'Qt Creator',"
               "'Qt Creator is a powerful cross-platform integrated "
               "development environment (IDE), including UI design tools "
               "and on-device debugging.')");
    query.exec("insert into items "
               "values(3, 3, 'Qt Project',"
               "'The Qt Project governs the open source development of Qt, "
               "allowing anyone wanting to contribute to join the effort "
               "through a meritocratic structure of approvers and "
               "maintainers.')");

    query.exec("create table images (itemid int, file varchar(20))");
    query.exec("insert into images values(0, 'images/qt-logo.png')");
    query.exec("insert into images values(1, 'images/qt-quick.png')");
    query.exec("insert into images values(2, 'images/qt-creator.png')");
    query.exec("insert into images values(3, 'images/qt-project.png')");

    return True


if __name__ == '__main__':
    app = QApplication(sys.argv)
    if not createConnection():
        raise Exception()
    #createRelationalTables()

    model = QSqlRelationalTableModel()

    initializeModel(model)

    view = createView(("Relational Table Model"), model)
    view.show()

    app.exec()
