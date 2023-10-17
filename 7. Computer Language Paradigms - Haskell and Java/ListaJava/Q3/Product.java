package ListaJava.Q3;

public class Product extends Data{
    
    private String ID;
    private String name;
    private int productQnt;
    private String departamentID;

    public Product(String ID, String name, int productQnt, String departamentID){
        this.ID = ID;
        this.name = name;
        this.productQnt = productQnt;
        this.departamentID = departamentID;
    }

    public void setProductID(String ID){
        this.ID = ID;
    }

    public String getProductID(){
        return this.ID;
    }

    public void setName(String name){
        this.name = name;
    }

    public String getName(){
        return this.name;
    }
    
    public void setProductQnt(int productQnt){
        this.productQnt = productQnt;
    }

    public int getProductQnt(){
        return this.productQnt;
    }

    public void setDepartamentID(String departamentID){
        this.departamentID = departamentID;
    }

    public String getDepartamentID(){
        return this.departamentID;
    }
}