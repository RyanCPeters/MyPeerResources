///**
// * @author Ryan Peters
// * @date 10/8/2017
// */
//public class dink {
//	/**
//	 * Write a description of class CoffeeMachine here.
//	 *
//	 * @author (your name)
//	 * @version (a version number or a date)
//	 */
//import java.util.Scanner; //allows for user input
//
//	public class CoffeeMachine {
//		public static void main() {
//			double price = 0.0;
//			int numOrders = getOrder();
//			System.out.println(price);
//			String drinkTypes = getTypes(numOrders);
//			System.out.println(drinkTypes);
//			getPrice(drinkTypes, price, numOrders);
//		}
//
//		public static double getPrice(String coffeeType, double price, int numOrders) {
//			double pr1 = 2.65;
//			double pr2 = 2.95;
//			double pr3 = 3.35;
//			double pr4 = 3.95;
//			double pr5 = 3.85;
//			double pr6 = 4.45;
//			int i = 1;
//			int currentOrder = 1;
//			//above lines set prices
//			int drinks = Integer.parseInt(coffeeType); //converts string to integer
//			int drink3 = drinks / 100; //obtains number of drink 3
//			int drink2 = (drinks % 100) / 10; //obtains the number of drink 2
//			int drink1 = (drinks % 10); //obtains the number of drink 1
//			while (currentOrder <= numOrders) { //ensures that the drink limit is checked
//				while (i < 7) { //ensures the iterator does not go in infinately
//					if (i == drink1) {  //checks to see if drink number is correct for current interation price
//						price += ("pr" + String.valueOf(i)); //supposed to concatanite the iteration and pr to form correct price variable, adds to current price
//					} else {
//						i++; //updates to next price if drink number is incorrect
//					}
//				}
//				i = 1; //resets iterator
//				while (i < 7) { //ensures the iterator does not go in infinately
//					if (i == drink2) { //checks to see if drink number is correct for current interation price
//						price += ("pr" + String.valueOf(i)); //supposed to concatanite the iteration and pr to form correct price variable, adds to current price
//					} else {
//						i++; //updates to next price if drink number is incorrect
//					}
//				}
//				i = 1; //resets iterator
//				while (i < 7) { //ensures the iterator does not go in infinately
//					if (i == drink3) { //checks to see if drink number is correct for current interation price
//						price += ("pr" + String.valueOf(i)); //supposed to concatanite the iteration and pr to form correct price variable, adds to current price
//					} else {
//						i++; //updates to next price if drink order is incorrect
//					}
//				}
//				currentOrder++; //iterates to next drink order
//			}
//			return price; //returns total price
//
//		}
//
//		public static int getOrder() {
//			Scanner in = new Scanner(System.in); //assigns Scanner to allow for input
//			System.out.println("Please enter the number of drinks you wish to order (1-3): ");
//			int orders = in.nextInt();
//			return orders;
//		}
//
//		public static String getTypes(int order) {
//			int taAm = 1;
//			int grAm = 2;
//			int taLa = 3;
//			int grLa = 4;
//			int taMo = 5;
//			int grMo = 6;
//			int i = 1;
//			String drinkOrders = "";
//			Scanner in = new Scanner(System.in);
//			while (i <= order) {
//				System.out.format("Enter the drink choice you wish for drink number %s: \n", i);
//				i++;
//				System.out.format("1 = Tall Americano    2 = Grande Americano \n 3 = Tall Latte    4 = Grande Latte \n 5 = Tall Mocha    6 = Grande Mocha/n/n");
//				String drink = in.next();
//				drinkOrders = drinkOrders + drink;
//			}
//			return drinkOrders;
//		}
//	}
//}
