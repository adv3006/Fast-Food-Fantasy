#include "customtrip.h"
#include "ui_customtrip.h"

/*************************************************************************
 * Class CustomTrip
 * This is a window where a custom trip can be chosen: specific restaurants
 * can be chosen to go to on a trip.
 *************************************************************************/
/*************************************************************************
* Constructors & Destructors
*************************************************************************/
/**
 * @brief CustomTrip
 * This is the constructor for the custom trip. It places widgets for the
 * appearance and function of the window, including connecting slots to the
 * dynamically made widgets.
 * @param rlist the pointer to the restaurant list
 * @param parent the parent window
 */
CustomTrip::CustomTrip(QVector<Restaurant> rlist, bool all, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomTrip)
{
    resList.SetRestaurantList(rlist);

    int gridIndex = 0;

    //set up ui
    ui->setupUi(this);

    // set window title
    this->setWindowTitle("Custom Trip");

    // set palette color to red text
    invalidPalette.setColor(QPalette::WindowText, Qt::red);
    // Default message color is red for error
    errorMessage = new QLabel("");
    errorMessage->setPalette(invalidPalette);

    // set minimum width of last column
    ui->gridLayout->setColumnMinimumWidth(3,210);

    QLabel *labelTitleName = new QLabel("Restaurant");
    QLabel *labelTitleDistance = new QLabel("Miles From Saddleback");
    if(!all)
    {
     QLabel *labelTitlePlanTrip = new QLabel("Plan Trip?");
     ui->gridLayout->addWidget(labelTitlePlanTrip,0,2);
    }

    ui->gridLayout->addWidget(labelTitleName,0,0);
    ui->gridLayout->addWidget(labelTitleDistance,0,1);

    for (unsigned int i = 0; i < resList.size(); i++) {
        // since we're putting stuff on top of the grid first, the index of each
        // checkbox should be considered different from loop variable
        gridIndex = i + 1;
        QLabel *labelName = new QLabel(resList.GetRestaurant(i).GetName());
        QLabel *distanceFromSBack = new QLabel(QString::number(resList.GetRestaurant(i).GetDistanceSB()));
        QCheckBox *checkbox = new QCheckBox();
        if(!all)
        {
            // put new checkbox in list
            checkboxList << checkbox;
        }
        ui->gridLayout->addWidget(labelName,gridIndex,0);
        ui->gridLayout->addWidget(distanceFromSBack,gridIndex,1);
        if(!all)
        {
            ui->gridLayout->addWidget(checkbox,gridIndex,2);
        }
    }
    // error message
    ui->gridLayout->addWidget(errorMessage,0,3);

    if(!all)
    {
        // confirm button
        QPushButton *confirmButton = new QPushButton("Confirm");
        ui->gridLayout->addWidget(confirmButton,1,3);
        connect(confirmButton, SIGNAL(clicked(bool)), this, SLOT(onConfirmButtonClick(bool)));
    }

    // cancel button
    QPushButton *cancelButton = new QPushButton("Cancel");
    ui->gridLayout->addWidget(cancelButton,2,3);
    // connect function to cancel button
    connect(cancelButton, SIGNAL(clicked(bool)), this, SLOT(onCancelButtonClick(bool)));

    if(all)
    {
        // SelectAll button
        QPushButton *SelectAllButton = new QPushButton("Continue");
        ui->gridLayout->addWidget(SelectAllButton,3,3);
        // connect function to selectAll button
        connect(SelectAllButton, SIGNAL(clicked(bool)), this, SLOT(onSelectAllClicked(bool)));
    }
}


/**
 * @brief ~CustomTrip
 * This is the destructor for custom trip, it deletes the ui
 */
CustomTrip::~CustomTrip()
{
    delete ui;
}

/*************************************************************************
* Slots
*************************************************************************/
/**
 * @brief onCancelButtonClick
 * This method is performed when the cancel button is clicked. It closes the
 * window.
 */
void CustomTrip::onCancelButtonClick(bool) {
    this->close();
}

/**
 * @brief onConfirmButtonClick
 * This method is performed when the confirm button is clicked, it will record
 * which checkboxes were clicked for the restaurants and bring up a shopping menu
 * of the restaurants for the trip
 */
void CustomTrip::onConfirmButtonClick(bool) {
    listOfIndices.clear();
    for (int i = 0; i < checkboxList.size(); i++) {
        if (checkboxList.at(i)->isChecked()) {
            listOfIndices.push_back(i);

        }
    }
    if (listOfIndices.size() > 0)
    {
        errorMessage->setText("");
        queueOfIndices = resList.distanceAlgorithm(listOfIndices);
        shoppingMenu *menu = new shoppingMenu(queueOfIndices,resList);
        // Remove ? Button from window
        menu->setWindowFlags(menu->windowFlags() & ~Qt::WindowContextHelpButtonHint);
        menu->exec();
    }
    else
    {
        errorMessage->setText("You must select at least one restaurant.");
    }


    //  closes window after confirm button
    if (listOfIndices.size() > 1)
    {
        this->close();
    }

}

void CustomTrip::onSelectAllClicked(bool)
{
    listOfIndices.clear();
    for(int i = 0; i < resList.size(); i++)
    {
        listOfIndices.push_back(i);
    }

    if (listOfIndices.size() > 0) {
        errorMessage->setText("");
        queueOfIndices = resList.distanceAlgorithm(listOfIndices);
        shoppingMenu *menu = new shoppingMenu(queueOfIndices,resList);
        // Remove ? Button from window
        menu->setWindowFlags(menu->windowFlags() & ~Qt::WindowContextHelpButtonHint);
        menu->exec();
    }

    this->close();

}
