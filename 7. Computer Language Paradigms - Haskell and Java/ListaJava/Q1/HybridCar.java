package ListaJava.Q1;

public class HybridCar extends Car{
 
    private String currentState;

    public HybridCar(String ID){
        super(ID);
        this.currentState = "landCar";
    }

    public HybridCar(String ID, double velocidadeMaxima, double potencia){
        super(ID, velocidadeMaxima, potencia);
        this.currentState = "landCar";
    }

    public void setCurrentState(String currentState) throws Exception{
        if(currentState.equals("landCar") || currentState.equals("aquaticCar")){
            this.currentState = currentState;
        }else{
            throw new Exception("Estado inválido");
        }
    }
    
    public String getCurrentState(){
        return this.currentState;
    }

    public void changeCurrentState(){
        if(this.currentState.equals("landCar")){
            this.currentState = "aquaticCar";
        }else{
            this.currentState = "landCar";
        }
    }
}