import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class QuizApp extends JFrame {
    private String[] questions = {"What is 2 + 2?", "What is the capital of India?", "What is Java?"};
    private String[][] options = {{"3", "4", "5", "6"}, {"Delhi", "Mumbai", "Pune", "Surat"}, {"Programming Language", "Stylesheet", "Animal", "Game"}};
    private int[] answers = {1, 0, 0};
    private int currentQuestion = 0, score = 0;

    private JLabel questionLabel;
    private JRadioButton[] optionButtons = new JRadioButton[4];
    private ButtonGroup optionGroup = new ButtonGroup();

    public QuizApp() {
        setTitle("Quiz Application");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        setLocationRelativeTo(null);
        
        questionLabel = new JLabel("", SwingConstants.CENTER);
        add(questionLabel, BorderLayout.NORTH);

        JPanel optionsPanel = new JPanel(new GridLayout(4, 1));
        for (int i = 0; i < 4; i++) {
            optionButtons[i] = new JRadioButton();
            optionGroup.add(optionButtons[i]);
            optionsPanel.add(optionButtons[i]);
        }
        add(optionsPanel, BorderLayout.CENTER);

        JButton nextButton = new JButton("Next");
        nextButton.addActionListener(new NextAction());
        add(nextButton, BorderLayout.SOUTH);

        loadQuestion();
        setVisible(true);
    }

    private void loadQuestion() {
        questionLabel.setText(questions[currentQuestion]);
        for (int i = 0; i < 4; i++) {
            optionButtons[i].setText(options[currentQuestion][i]);
        }
    }

    private class NextAction implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            int selectedOption = -1;
            for (int i = 0; i < 4; i++) {
                if (optionButtons[i].isSelected()) {
                    selectedOption = i;
                    break;
                }
            }
            if (selectedOption == answers[currentQuestion]) {
                score++;
            }
            currentQuestion++;
            if (currentQuestion < questions.length) {
                loadQuestion();
            } else {
                JOptionPane.showMessageDialog(null, "Quiz Over! Your Score: " + score);
                System.exit(0);
            }
        }
    }

    public static void main(String[] args) {
        new QuizApp();
    }
}
