//Question 2

class Invoice {
    private String partNumber;
    private String partDescription;
    private int quantity;
    private double pricePerItem;

    public Invoice(String partNumber, String partDescription, int quantity, double pricePerItem) {
        this.partNumber = partNumber;
        this.partDescription = partDescription;
        this.quantity = Math.max(quantity, 0);
        this.pricePerItem = Math.max(pricePerItem, 0.0);
    }

    public String getPartNumber() {
        return partNumber;
    }

    public void setPartNumber(String partNumber) {
        this.partNumber = partNumber;
    }

    public String getPartDescription() {
        return partDescription;
    }

    public void setPartDescription(String partDescription) {
        this.partDescription = partDescription;
    }

    public int getQuantity() {
        return quantity;
    }

    public void setQuantity(int quantity) {
        this.quantity = Math.max(quantity, 0);
    }

    public double getPricePerItem() {
        return pricePerItem;
    }

    public void setPricePerItem(double pricePerItem) {
        this.pricePerItem = Math.max(pricePerItem, 0.0);
    }

    public double getInvoiceAmount() {
        return quantity * pricePerItem;
    }
}

public class InvoiceTest {
    public static void main(String[] args) {
        Invoice invoice = new Invoice("001", "Widget", 10, 5.99);
        System.out.println("Invoice Amount: " + String.format("%.2f",invoice.getInvoiceAmount()));

    }
}
