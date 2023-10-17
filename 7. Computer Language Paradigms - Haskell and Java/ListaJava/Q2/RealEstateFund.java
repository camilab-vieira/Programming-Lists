package ListaJava.Q2;

public class RealEstateFund extends Investiment{
   
    
    public RealEstateFund(){
        super();
    }
    
    public RealEstateFund(double incomeRate, String code){
        super(incomeRate, code);
    }
    
    public RealEstateFund(double incomeRate, String code, double investedMoney){
        super(incomeRate, code, investedMoney);
    }
    
    @Override
    public double yield(){
        return getInvestedMoney() * getIncomeRate()/100;
    };

    @Override
    public double yield(int time){
        return getInvestedMoney() * Math.pow((1 + getIncomeRate()/100), time) - getInvestedMoney();
    }
}