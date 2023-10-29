import random  # For simulating live data, replace with actual sensor data
import tkinter as tk

def update_bar():
    # Simulate live sensor data (replace this with actual data retrieval)
    new_fill_level = random.uniform(0, 1)  # Simulated value between 0 and 1

    fill_width = int(new_fill_level * (bar_width - 2))  # -2 to account for borders
    fill_bar.itemconfig(fill, width=fill_width)
    fill_bar.itemconfig(fill, fill='green' if new_fill_level < 0.7 else 'red')  # Change color based on fill level
    
    # Update the percentage indicator
    percentage = int(new_fill_level * 100)
    percent_label.config(text=f"{percentage}%")
    
    root.after(1000, update_bar)  # Update the bar and percentage every 1000 milliseconds (1 second)

# Create the main window
root = tk.Tk()
root.title("Smart Dustbin Monitor")

# Create a frame to center the content both horizontally and vertically
center_frame = tk.Frame(root)
center_frame.grid(row=0, column=0, padx=10, pady=10)

# Create a canvas to center the fill bar and percentage label
canvas = tk.Canvas(center_frame, width=200, height=100)
canvas.pack(expand=True)

# Create the fill bar
bar_width = 180
bar_height = 20
fill_bar = tk.Canvas(canvas, width=bar_width+1, height=bar_height+1, bg='white', highlightthickness=1, highlightbackground='black')
fill_bar.pack(expand=True)
fill = fill_bar.create_rectangle(1, 1, bar_width, bar_height, fill='green', outline='')

# Create the percentage label
percent_label = tk.Label(canvas, text='0%', font=('Arial', 12))
percent_label.pack(expand=True)

# Center the canvas in the frame
center_frame.update()
canvas_width = canvas.winfo_width()
canvas_height = canvas.winfo_height()
x = (center_frame.winfo_width() - canvas_width) // 2
y = (center_frame.winfo_height() - canvas_height) // 2
canvas.place(relx=.5, rely=.5, anchor="center")

update_bar()

root.mainloop()