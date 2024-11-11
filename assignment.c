#include <stdio.h>
#include <stdlib.h>

double base_comm(double s, double c){ // s = total sales, c = commission rate(0.2)
    int base_commission;

    base_commission = s * c;
    return base_commission;

}

int bonus(double t) { // total_sales_week = t
    int b;  // b = bonus
    if (t > 5000) {

        b = (t - 5000) * 0.1;  
    } else {
        b = 0;
    }
    return b;
}

int total_commission(double s, double c,int b) {
    int base_commission;
    int total_commission;

    base_commission = s * c;

    total_commission = base_commission + b;
    return total_commission;
}

double tax_deduct(int tocom) { // tocom = total commission
    double tax;
    tax = tocom * 0.05;
    // printf("\nTax Deduction: %d",tax)
    return tax;
}

double net_comm(int tocom, double texde) {  // tocom = total commission, texde = tax deduct
    double net_commission;

    net_commission = tocom - texde;
    return net_commission;

}

int performance(double netcomm) {  // netcomm = net commission
    int performance_bonus;
    if(netcomm > 1000) {
        performance_bonus += 100;
    } else {
        performance_bonus = 0;
    }
    return performance_bonus;
}

int main () {    
    int id_num;
    double total_sales_week;
    double commission_rate = 0.2;

    Beginning:
    printf("Enter your id number: ");
    scanf("%d",&id_num);

    printf("Enter your Total sales in the week: RM");
    scanf("%lf",&total_sales_week);

    printf("\nId: %d",id_num);

    int baseCommission = base_comm(total_sales_week, commission_rate);
    printf("\nBase commission: %d",baseCommission);

    int Bonus = bonus(total_sales_week);
    printf("\nBonus: %d",Bonus);

    int totalCommission = total_commission(total_sales_week, commission_rate, Bonus);
    printf("\nTotal commission: %d",totalCommission);

    double Tax = tax_deduct(totalCommission);
    printf("\nTax deduction: %.2lf",Tax);

    double netComm = net_comm(totalCommission, Tax);
    printf("\nNet commission: %.2lf",netComm);

    int performanceBonus = performance(netComm);
    printf("\nPerformance bonus: %d",performanceBonus);

    printf("\nWould you like to continue (y/n): ");

    char choice;

    while (scanf(" %c",&choice))
    {
        if (choice == 'y') {
            printf("\nSuccess!");
            goto Beginning;
        } else {
            goto End;
        }
    }

    End:
    printf("\nHello!");
}