package ListaJava.Q1;

public class Car {
    
    private String ID;
    private double velocidadeMaxima;
    private double potencia;

    public Car(String ID){
        this.ID = ID;
        this.velocidadeMaxima = 300;
        this.potencia = 400;
    }

    public Car(String ID, double velocidadeMaxima, double potencia){
        this.ID = ID;
        this.velocidadeMaxima = velocidadeMaxima;
        this.potencia = potencia;
    }

    public void setID(String ID){
        this.ID = ID;
    }
    
    public String getID(){
        return this.ID;
    }
    
    public void setVelocidadeMaxima(double velocidadeMaxima) throws Exception{
        if(velocidadeMaxima > 0){
            this.velocidadeMaxima = velocidadeMaxima;
        }else{
            throw new Exception("Velocidade máxima menor que zero");
        }
    }

    public double getVelocidadeMaxima(){
        return this.velocidadeMaxima;
    }

    public void setPotencia(double potencia) throws Exception{
        if(potencia > 0){
            this.potencia = potencia;
        }else{
            throw new Exception("Potência menor que zero");
        }
    }

    public double getPotencia(){
        return this.potencia;
    }
}