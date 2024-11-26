import java.awt.*;
import java.text.SimpleDateFormat;
import java.util.Date;
import javax.swing.*;

public class DigitalClock extends JFrame {
    private JLabel timeLabel;  
    private Timer timer;      

    public DigitalClock() {
        timeLabel = new JLabel();
        timeLabel.setFont(new Font("Times New Roman", Font.BOLD, 40)); 
        timeLabel.setBackground(new Color(123,150,250));
        timeLabel.setHorizontalAlignment(SwingConstants.CENTER);
        setLocationRelativeTo(null);

        setLayout(new BorderLayout());
        add(timeLabel, BorderLayout.CENTER);

        timer = new Timer(1000, e -> updateTime());
        timer.start();  
        updateTime();

        setTitle("Digital Clock");
        setSize(450, 250);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null); 
        setVisible(true);
    }
    private void updateTime() {

        SimpleDateFormat sdf = new SimpleDateFormat("HH:mm:ss");
        String currentTime = sdf.format(new Date());
        timeLabel.setText(currentTime);
    }
    public static void main(String[] args) {
        // Create an instance of the DigitalClockApp
        SwingUtilities.invokeLater(() -> new DigitalClock());
    }
}