package ListaJava.Q3;

import java.util.ArrayList;
import java.util.List;

public class DepartamentDB {

    private List<Departament> departaments;
    private static String ID;

    public DepartamentDB(){
        this.departaments = new ArrayList<>();
    }

    public static void setID(String id){
        ID = id;
    }

    public static String getID(){
        return ID;
    }

    public void setDepartaments(List<Departament> departaments){
        this.departaments = departaments;
    }

    public List<Departament> getDepartaments(){
        return this.departaments;
    }

    public Boolean findDepartament(String ID){
        for(Departament departament : this.departaments){
            if(departament.getDepartmentID().equals(ID)){
                return true;
            }
        }
        return false;
    }

    public void add(Departament departament){
        for(Departament departament1 : this.departaments){
            if(departament1.getDepartmentID().equals(departament.getDepartmentID())){
                return;
            }
        }
        this.departaments.add(departament);
    }

    public void remove(String ID, ProductsDB productsDB){
        for(Departament departament : this.departaments){
            if(departament.getDepartmentID().equals(ID)){
                this.departaments.remove(this.departaments.indexOf(departament));
                productsDB.removeDepartamentProducts(ID);
                return;
            }
        }
    }

    public void update(String ID, String name){
        for(Departament departament : this.departaments){
            if(departament.getDepartmentID().equals(ID)){
                departament.setDepartmentName(name);
            }
        }
    }

    public void list(){
        System.out.println("Lista de Departamentos:");
        for(Departament departament : this.departaments){
            System.out.println(departament.getDepartmentID());
            System.out.println(departament.getDepartmentName());
            System.out.println();
        }
    }
}