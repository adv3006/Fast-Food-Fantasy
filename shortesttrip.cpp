#include "shortesttrip.h"
#include "ui_shortesttrip.h"

/*************************************************************************
 * Class ShortestTrip
 * This class is the window of the shortest trip which allows you to
 * choose the starting restaurant and total number of restaurants to visit
 * in the most efficient order.
 *************************************************************************/
/*************************************************************************
* Constructors & Destructors
*************************************************************************/
/**
 * @brief ShortestTrip
 * This is the constructor for the shortest trip window which allows you to
 * choose the starting restaurant and total number of restaurants to visit in
 * the most efficient order.
 * @param rlist pointer to the restaurant list
 * @param parent the parent window
 */
ShortestTrip::ShortestTrip(QVector<Restaurant> rlist, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShortestTrip)
{
    resList.SetRestaurantList(rlist);

    // since we're putting stuff on top of the grid first, the index of each
    // checkbox should be considered different from loop variable

    int gridIndex = 0;
    ui->setupUi(this);

    // set window title
    this->setWindowTitle("Shortest Trip");

    QLabel *labelTitleName = new QLabel("Restaurant");
    QLabel *labelTitleDistance = new QLabel("Miles From Saddleback");
    QLabel *labelTitlePlanTrip = new QLabel("Starting Restaurant?");
    ui->gridLayout->addWidget(labelTitleName,0,0);
    ui->gridLayout->addWidget(labelTitleDistance,0,1);
    ui->gridLayout->addWidget(labelTitlePlanTrip,0,2);
    for (unsigned int i = 0; i < resList.size(); i++) {
        // since we're putting stuff on top of the grid first, the index of each
        // checkbox should be considered different from loop variable
        gridIndex = i + 1;
        QLabel *labelName = new QLabel(resList.GetRestaurant(i).GetName());
        QLabel *distanceFromSBack = new QLabel(QString::number(resList.GetRestaurant(i).GetNum()));
        QRadioButton *radioButton = new QRadioButton();

        // put new checkbox in list
        radioButtonList << radioButton;

        ui->gridLayout->addWidget(labelName,gridIndex,0);
        ui->gridLayout->addWidget(distanceFromSBack,gridIndex,1);
        ui->gridLayout->addWidget(radioButton,gridIndex,2);
    }
    // select first restaurant
    radioButtonList.at(0)->setChecked(true);
    // confirm button
    QPushButton *confirmButton = new QPushButton("Confirm");
    ui->gridLayout->addWidget(confirmButton,0,3);
    connect(confirmButton, SIGNAL(clicked(bool)), this, SLOT(onConfirmButtonClick(bool)));


    // cancel button
    QPushButton *cancelButton = new QPushButton("Cancel");
    ui->gridLayout->addWidget(cancelButton,1,3);
    // connect function to cancel button
    connect(cancelButton, SIGNAL(clicked(bool)), this, SLOT(onCancelButtonClick(bool)));

    // spinner box
    restaurantMax = new QSpinBox();
    restaurantMax->setMaximum(resList.size());
    restaurantMax->setMinimum(1);
    ui->gridLayout->addWidget(new QLabel("# of Restaurants To Visit"),2,3);
    ui->gridLayout->addWidget(restaurantMax,3,3);

    // select all button
    QPushButton *selectAll = new QPushButton("Select All");
    ui->gridLayout->addWidget(selectAll,4,3);
    // connect function to cancel button
    connect(selectAll, SIGNAL(clicked(bool)), this, SLOT(onSelectAllButtonClick(bool)));
}

/**
 * @brief ~ShortestTrip
 * This is the destructor which deletes the ui
 */
ShortestTrip::~ShortestTrip()
{
    delete ui;
}

/*************************************************************************
* Slots
*************************************************************************/
/**
 * @brief onConfirmButtonClick
 * This method is performed when the confirm button is clicked. The
 * trip/shopping menu is brought up with the starting restaurants and the
 * closest restaurants (of a number specified by the user in the spinner box)
 * to it.
 */
void ShortestTrip::onConfirmButtonClick(bool) {
    unsigned int max = restaurantMax->value();
    bool foundSelectedRadioButton = false;
    int count = 0;
    unsigned int selectedIndex = 0;
    QVector<int> listOfIndices;

    while (count < radioButtonList.size() && !foundSelectedRadioButton) {
        if (radioButtonList.at(count)->isChecked()) {
            selectedIndex = count;
            foundSelectedRadioButton = true;
        }
        else {
            count++;
        }
    }

    for (unsigned int i = 0; i < resList.size(); i++) {
        if (i != selectedIndex) {
            listOfIndices.push_back(i);
        }

    }

    queue<int> initialQueue = resList.distanceAlgorithm(listOfIndices, true, selectedIndex);
    queue<int> queueOfIndices;
    unsigned int initialQueueSize = initialQueue.size();
    for (unsigned int i = 0; i < initialQueueSize && i < max; i++) {
        queueOfIndices.push(initialQueue.front());
        initialQueue.pop();
    }
    if (queueOfIndices.size() >= 1) {
        shoppingMenu *menu = new shoppingMenu(queueOfIndices,resList);
        // Remove ? Button from window
        menu->setWindowFlags(menu->windowFlags() & ~Qt::WindowContextHelpButtonHint);
        menu->exec();
    }

    //closes window after confirm button
    this->close();
}

/**
 * @brief onCancelButtonClick
 * This method is performed when the cancel button is clicked. It closes the
 * window.
 */
void ShortestTrip::onCancelButtonClick(bool) {
    this->close();
}

/**
 * @brief onSelectAllButtonClick
 * This method selects the total amount of restaurants in the spinner box,
 * so the user can visit all of the restaurants.
 */
void ShortestTrip::onSelectAllButtonClick(bool) {
    restaurantMax->setValue(resList.size());
}
