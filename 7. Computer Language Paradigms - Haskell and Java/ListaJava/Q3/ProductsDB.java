package ListaJava.Q3;

import java.util.ArrayList;
import java.util.List;

public class ProductsDB {
    private List<Product> products;
    private static String ID;

    public ProductsDB(){
        this.products = new ArrayList<>();
    }

    public static void setID(String id){
        ID = id;
    }

    public static String getID(){
        return ID;
    }

    public void setProducts(List<Product> products){
        this.products = products;
    }

    public List<Product> getProducts(){
        return this.products;
    }

    public void add(Product product, DepartamentDB departamentDB){
        if(departamentDB.findDepartament(product.getDepartamentID())){
            for(Product product1 : this.products){
                if(product1.getProductID().equals(product.getProductID())){
                    return;
                }
            }
            this.products.add(product);
        }
    }

    public void remove(String ID){
        for(Product product : this.products){
            if(product.getProductID().equals(ID)){
                this.products.remove(this.products.indexOf(product));
                return;
            }
        }
    }

    public void removeDepartamentProducts(String ID){
        for(Product product : this.products){
            if(product.getDepartamentID().equals(ID)){
                this.products.remove(this.products.indexOf(product));
            }
        }
    }

    public void update(String ID, int productQnt){
        for(Product product : this.products){
            if(product.getProductID().equals(ID)){
                product.setProductQnt(productQnt);
            }
        }
    }

    public void update(String ID, String name){
        for(Product product : this.products){
            if(product.getProductID().equals(ID)){
                product.setName(name);
            }
        }
    }

    public void update(String ID, String name, int productQnt){
        for(Product product : this.products){
            if(product.getProductID().equals(ID)){
                product.setName(name);
                product.setProductQnt(productQnt);
            }
        }
    }

    public void list(){
        System.out.println("Lista de Produtos:");
        for(Product product : this.products){
            System.out.println(product.getProductID());
            System.out.println(product.getName());
            System.out.println(product.getProductQnt());
            System.out.println(product.getDepartamentID());
            System.out.println();
        }
    }

    public void list(String departamentID){
        System.out.println("Lista de Produtos por Departamento ("+departamentID+"):");
        for(Product product : this.products){
            if(product.getDepartamentID().equals(departamentID)){
                System.out.println(product.getProductID());
                System.out.println(product.getName());
                System.out.println(product.getProductQnt());
                System.out.println(product.getDepartamentID());
                System.out.println();
            }
        }
    }
}