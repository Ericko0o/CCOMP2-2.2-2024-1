#include "Date.h"

int main() {
    Date date1(3, 1, 2020);
    Date date2(15, 14, 2019);
    Date date3(20, 12, 1500);

    date1.displayDate();
    date2.displayDate();
    date3.displayDate();

    return 0;
}
