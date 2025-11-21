🏥 Clinic Appointment System

A simple C console application for managing doctor appointments. It allows patients to book slots and doctors to view the daily queue, running entirely in the terminal.

✨ Key Features

Booking System: Records Patient Name, Medical Problem (multi-word support), and Date.

Conflict Prevention: Automatically rejects bookings if the chosen date is already taken.

Input Validation: Ensures dates follow the YYYY-MM-DD format.

Queue View: Displays all upcoming appointments.

🚀 Quick Start

1. Compile

Open your terminal/command prompt and run:

gcc clinic_system.c -o clinic


2. Run

Windows: clinic.exe

Mac/Linux: ./clinic

⚙️ Configuration

Max Capacity: Defined by MAX_APPTS (default: 5).

Storage: In-memory (Data is reset when the program closes).
