import java.util.ArrayList;

public class App {
    public static void main(String[] args) throws Exception {
        
        ArrayList<ArrayList<String>> groceryList = new ArrayList<ArrayList<String>>();

        ArrayList<String> bakeryList = new ArrayList<String>();
        bakeryList.add("pasta");
        bakeryList.add("garlic bread");
        bakeryList.add("donuts");
        
        ArrayList<String> produceList = new ArrayList<String>();
        produceList.add("tomatoes");
        produceList.add("zucchini");
        produceList.add("peppers");
        
        ArrayList<String> drinksList = new ArrayList<String>();
        drinksList.add("coke");
        drinksList.add("pepsi");
        drinksList.add("water");

        groceryList.add(bakeryList);
        groceryList.add(produceList);
        groceryList.add(drinksList);

        groceryList.get(0).get(0);
    }
}
