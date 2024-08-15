# Project Title: Project Management System

## Overview
Aplikasi C++ ini adalah sistem manajemen proyek yang dirancang untuk mengelola proyek secara efisien dengan mengorganisir, melacak, dan memfasilitasi pemindahan proyek antara status yang berbeda, seperti "Work In Progress" (WIP) dan "Finished". Aplikasi ini memanfaatkan struktur data dasar seperti Struct, Sorting, dan Queue untuk memungkinkan manajemen proyek yang lancar.

## Screenshots

![App Screenshot](https://via.placeholder.com/468x300?text=App+Screenshot+Here)


## Features
- **Add New Project**: Tambahkan proyek baru dengan detail penting.
- **Delete Project**: Hapus proyek dari daftar sesuai kebutuhan.
- **Search Projects**: Cari proyek tertentu dengan cepat di dalam daftar.
- **Sort Projects**: Mengatur proyek secara berurutan berdasarkan kriteria tertentu (misalnya, deadline, prioritas).
- **Move Project Status**: Memindahkan status proyek antara "Work In Progress" dan "Finished" dengan mudah.

## Data Structures Used
- **Struct**: Digunakan untuk mendefinisikan struktur proyek, termasuk atribut seperti nama proyek, deskripsi, deadline, status, dll.
- **Sorting**: Diimplementasikan untuk memungkinkan proyek disortir berdasarkan berbagai kriteria, memudahkan untuk memprioritaskan dan mengelola tugas.
- **Queue**: Digunakan untuk mengelola aliran proyek antara status yang berbeda, memastikan bahwa tugas diproses secara FIFO (first-in, first-out) jika diperlukan.

## How to Run the Project
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/project-management-system.git
1. **Navigate to the Project Directory**:
   ```bash
   cd project-management-system
1. **Compile the Program:**:
   ```bash
   g++ main.cpp -o projectManager

## Usage Instructions

### Adding a New Project:
- Masukkan detail proyek seperti nama, deskripsi, deadline, dll.
- Proyek akan ditambahkan ke daftar dan dikategorikan di bawah "Work In Progress".

### Viewing Projects:
- Program akan menampilkan daftar proyek, yang dapat difilter atau diurutkan berdasarkan berbagai kriteria.

### Moving Project Status:
- Proyek dapat dipindahkan dari "Work In Progress" ke "Finished" dengan memilih proyek yang diinginkan dan memilih opsi yang sesuai.

### Deleting a Project:
- Pilih proyek dari daftar dan hapus jika sudah tidak diperlukan.

### Searching for a Project:
- Gunakan fungsi pencarian untuk menemukan proyek berdasarkan nama atau atribut lainnya.

## Contributing
1. Fork repository ini.
2. Buat branch baru (`git checkout -b feature-branch`).
3. Lakukan perubahan dan commit (`git commit -m 'Add some feature'`).
4. Push ke branch (`git push origin feature-branch`).
5. Buat Pull Request baru.

## License
Proyek ini dilisensikan di bawah MIT License. Lihat file [LICENSE](LICENSE) untuk informasi lebih lanjut.

## Contact
Untuk pertanyaan atau saran, silakan hubungi saya di aanvinanta5@gmail.com.
