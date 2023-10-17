package ListaJava.Q3;

public class Departament extends Data{
    
    private String ID;
    private String name;

    public Departament(String ID, String name){
        this.ID = ID;
        this.name = name;
    }
    
    public void setDepartmentID(String ID){
        this.ID = ID;
    }

    public String getDepartmentID(){
        return this.ID;
    }

    public void setDepartmentName(String name){
        this.name = name;
    }

    public String getDepartmentName(){
        return this.name;
    }
}