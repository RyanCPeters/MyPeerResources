
/**
 * Write a description of class CoffeeMachine here.
 *
 * @author (your name)
 * @version (a version number or a date)
 *
 */


import java.util.Scanner; //allows for user input


public class CoffeeMachine{
	private static final int NUM_DRNK_OPTS = 6;

	/**
	 *
	 */
	public static void main(String[] args){
		double price = 0.0;
		int numOrders = getOrder();
		System.out.println(numOrders);
		String drinkTypes = getTypes(numOrders);
		System.out.println(drinkTypes);
		price = getPrice(drinkTypes, price, numOrders);
		System.out.println(price);

	}

	/**
	 *
	 * @param coffeeType
	 * @param price
	 * @param numOrders
	 * @return
	 */
	public static double getPrice(String coffeeType, double price, int numOrders){
		/*
		  naming convention for following variables
			a -> Americano
			l -> Latte
			m -> mocha
			T -> tall
			G -> grande

			so... aT = Tall Americano
				  mG = Grande Mocha
				  etc...
		 */
		// setting the prices of the different coffees
		double aT, aG, lT, lG, mT, mG;
		aT = 2.65;
		aG = 2.95;
		lT = 3.35;
		lG = 3.95;
		mT = 3.85;
		mG = 4.45;

		int drink1, drink2, drink3, drinks = Integer.parseInt(coffeeType); //converts string to integer
		drink3 = drinks / 100; //obtains number of drink 3
		drink2 = (drinks % 100)/10; //obtains the number of drink 2
		drink1 = (drinks % 10); //obtains the number of drink 1


		for( int i = 0; i < numOrders; i++){
			for(int k = 1; k <= NUM_DRNK_OPTS; k++){
				if(k == drink1 || k == drink2 || k == drink3) {
					switch (k) {
						case 1:
							price += aT;
							break;
						case 2:
							price += aG;
							break;
						case 3:
							price += lT;
							break;
						case 4:
							price += lG;
							break;
						case 5:
							price += mT;
							break;
						case 6:
							price += mG;
							break;
						default:
							continue;
					}// end of switch block
					break;
				}// end of if block
			}// end of for(k) loop
		}// end of for(i) loop
		return price; //returns total price

	}

	/**
	 *
	 * @return
	 */
	public static int getOrder(){
		Scanner in = new Scanner(System.in); //assigns Scanner to allow for input
		System.out.println("Please enter the number of drinks you wish to order (1-3): ");
		return in.nextInt();
	}

	/**
	 *
	 * @param order
	 * @return
	 */
	public static String getTypes(int order){
		StringBuilder drinkOrders = new StringBuilder();
		Scanner in = new Scanner(System.in);
		for(int i = 0; i < order; i++){
			System.out.format("Enter the drink choice you wish for drink number %s: \n", i);
			System.out.format("%-17s\t%s\n%-17s\t%s\n%-17s\t%s\n\n"
					,"1 = Tall Americano", "2 = Grande Americano"
					,"3 = Tall Latte"     ,"4 = Grande Latte"
					,"5 = Tall Mocha"     ,"6 = Grande Mocha");
			drinkOrders.append(in.next());
		}
		return drinkOrders.toString();
	}
}

