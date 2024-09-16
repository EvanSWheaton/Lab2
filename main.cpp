#include <iomanip>
#include <iostream>

using namespace std;

class fraction {
   int numerator;
   int denominator;
public:
   fraction (){numerator = 0; denominator = 1;}   // inline costructor creates fraction 0/1
   fraction operator+ (fraction);
   fraction operator* (fraction);
   friend fraction operator* (int, fraction);
   friend ostream& operator<< (ostream&, fraction);
   friend istream& operator>> (istream&, fraction&);
   friend fraction operator* (fraction, int);
   fraction operator- (fraction);
   fraction operator/ (fraction);

   // add more functions below
};

/*
 * Method to output a mixed fraction using the output operator.
 * left: in-out param storing output stream.
 * right: in param containing fraction to output.
 * Returns pointer to output stream.
 *
 * Note: output is not a simplified fraction, except for 0.
 */
ostream& operator<< (ostream& co, fraction f)
{
   // determine if a mixed fraction
   if (f.numerator >= f.denominator) {
      co << f.numerator / f.denominator << " ";
      f.numerator %= f.denominator;
   }
   if (f.numerator > 0 or f.numerator < 0)
      co << f.numerator << "/" << f.denominator;
   else
      co << 0;

   return co;
}

/*
 * Method to input a fraction using the input operator.
 * left: in-out param that contains input stream.
 * right: in-out param containing fraction to output.
 * Returns pointer to input stream.
 */
istream& operator>> (istream& ci, fraction& f)
{
   ci >> f.numerator;
   ci.get();
   ci >> f.denominator;
   return ci;
}

/*
 * Method to add: fraction1 + fraction2.
 * right: in param containing fraction2 to add to fraction1.
 * Returns sum of the fractions.
 */
fraction fraction :: operator+ (fraction right)
{
   fraction sum;  // sum of two fractions

   // make common denominator
   sum.denominator = denominator * right.denominator;

   // find new numerators and add together
   sum.numerator = numerator * (sum.denominator / denominator) +
                   right.numerator * (sum.denominator / right.denominator);

   // return sum
   return sum;
}

/*
 * Method to multiply: fraction1 * fraction2.
 * right: in param containing fraction2 to multiply by fraction1.
 * Returns product of the fractions.
 */
fraction fraction :: operator* (fraction right)
{
   fraction prod;  // product of two fractions

   prod.numerator = numerator * right.numerator;
   prod.denominator = denominator * right.denominator;

   return prod;
}

/*
 * Method to multiply: integer * fraction2.
 * left: in param containing an integer.
 * right: in param containing fraction2 to multiply by integer.
 * Returns product of the integer * fraction2.
 */
fraction operator* (int left, fraction right)
{
   fraction prod;  // product of two fractions

   prod.numerator = left * right.numerator;
   prod.denominator = right.denominator;

   return prod;
}

/*
 * Method to multiply: fraction1 * integer.
 * left: in param containing fraction1 to multiply by integer.
 * right: in param containing an integer.
 * Returns product of the fraction1 * integer.
 */
fraction operator* (fraction left, int right)
{
   return right*left;
}

/*
 * Method to subtract: fraction1 - fraction2.
 * right: in param containing fraction2 to subtract from fraction1.
 * Returns difference of the fractions.
 */
fraction fraction :: operator- (fraction right)
{
   fraction diff;  // difference of two fractions

   // make common denominator
   diff.denominator = denominator * right.denominator;

   // find new numerators and subtract them
   diff.numerator = numerator * (diff.denominator / denominator) -
                   right.numerator * (diff.denominator / right.denominator);

   return diff;
}

/*
 * Method to divide: fraction1 / fraction2.
 * right: in param containing fraction2 to divide by fraction1.
 * Returns quotient of the fractions.
 */
fraction fraction :: operator/ (fraction right)
{
   fraction quot;  // quotient of two fractions

   quot.numerator = numerator * right.denominator;
   quot.denominator = denominator * right.numerator;

   return quot;
}


int main() {
   fraction fract1, fract2;   // two fraction objects

   // test for extraction operator >>
   cout << "Enter two fractions: ";
   cin >> fract1 >> fract2;
   cout << "\n";

   // tests for insertion operator >>
   cout << "The fractions are  : " << fract1;
   cout << " and " << fract2 << endl;

   // tests for multiplication
   cout << "\nmultiplication: " << endl;
   cout << "fraction x fraction: " << fract1 << " x " << fract2 << " = " << fract1 * fract2 << endl;
   cout << "int x fraction : 5 x " << fract1 << " = " << 5 * fract1 << endl;
   cout << "fraction x int : " << fract1 << " x 5 = " << fract1 * 5 << endl;

   // tests for subtraction
   cout << "\nsubtractionn: " << fract1 << " - " << fract2 << " = " << fract1 - fract2 << endl;
   cout << "subtractionn: " << fract2 << " - " << fract1 << " = " << fract2 - fract1 << endl;

   // test for division
   cout << "\ndivision: " << fract1 << " / " << fract2 << " = " << fract1 / fract2 << endl;

   return 0;
}