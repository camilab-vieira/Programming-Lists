package ListaJava.Q3;

public class MainClass {
    public static void main(String args[]){
        ProductsDB productsDB = new ProductsDB();
        DepartamentDB departamentDB = new DepartamentDB();

        productsDB.add(new Product("00", "Sabonete Nivel", 10, "0a"), departamentDB);
        departamentDB.add(new Departament("0a", "Higiene Pessoal"));
        productsDB.add(new Product("00", "Sabonete Nivel", 10, "0a"), departamentDB);
        productsDB.add(new Product("01", "Shampoo Aussie", 20, "0a"), departamentDB);
        departamentDB.add(new Departament("0b", "Fitness"));
        productsDB.update("01", "Shampoo Aussie 90g");
        productsDB.add(new Product("02", "Whey Max 900g", 5, "0b"), departamentDB);
        productsDB.remove("00");
        productsDB.list("0a");
        departamentDB.remove("0a", productsDB);
        departamentDB.list();
        productsDB.list();
    }
}
