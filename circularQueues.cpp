/**
 * @mainpage Doccumentation circular Queues
 * 
 * @section Introduction
 * project ini merupakan project struktur data
 * menggunakan struktur data Queues dengna pendekatan circular array.
 * 
 * @section Operations
 * - en queue for insert elements into queues
 * - de queue for delete elements from queues
 * - show data
 * 
 * @section How to use
 * 1. Insert
 * 2. Delete 
 * 3. Display 
 * 4. Exit 
 * 
 * @author profile 
 * - Nama   : Zaky Ibnu Sofyan 
 * - NIM    : 20240140206
 * - Kelas  : E
 * 
 * @brief 
 * @version 0.1
 * @date 2025-06-23
 * 
 * @copyright Gibran@umy.ac.id (c) 2025
 * 
 */

#include <iostream>
using namespace std;


/**
 * @class Queues
 * @brief Kelas ini digunakan untuk mengoprasikan queues
 * 
 */
class Queues
{
private:
  int FRONT; ///< private variable front untuk menyimpan posisi depan antrian
  int REAR; ///< variable private rear untuk menyimpan posisi belakanng antrian
  int max = 5; ///< variable private max untuk menyimpan ukuran maximum antrian
  int queue_array[5]; ///< queue_array untuk menyimpan elemen antrian

public:
  /**
   * @brief Construct a new Queues object
   * set default queues NULL
   * with front = -1 and rear = -1 
   */
  Queues()
  {
    FRONT = -1;
    REAR = -1;
  }

  /**
   * @brief Methode for entering data into Queues
   * data dimasukkan ke queue_array pada posisi REAR
   * 
   */
  void insert()
  {
    int num; ///< variable untuk menyimpan data yang akan dimasukkan 
    cout << "Enter a number : ";
    cin >> num;
    cout << endl;

    // cek apakah antrian penuh
    if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1))
    {
      cout << "\nQueue overflow\n";
      return;
    }

    // cek apakah antrian kosong
    if (FRONT == -1)
    {
      FRONT = 0;
      REAR = 0;
    }
    else
    {
      // jika REAR berada di posisi terakhir array, kembali ke awal array
      if (REAR == max - 1)
        REAR = 0;
      else
        REAR = REAR + 1;
    }
    queue_array[REAR] = num;
  }

  /**
   * @brief Methode untuk menghapus data dalam antrian
   * data yang ada di dalam front akan dihapus
   * 
   */
  void remove()
  {
    // cek apakah antrian kosong
    if (FRONT == - 1)
    {
      cout << "Queue underflow\n";
      return;
    }
    cout << "\nThe element deleted from the queue is : " << queue_array[FRONT] << "\n";

    // cek jika antrian hanya memiliki satu elemen
    if (FRONT == REAR)
    {
      FRONT = -1;
      REAR = -1;
    }
    else
    {
      // jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
      if (FRONT == max -1)
        FRONT = 0;
      else
        FRONT = FRONT + 1; 
    }
  }

  /**
   * @brief Methode untuk menampilkan element yang ada di dalam array
   * menampilkan data yang ada di dalam front hingga rear
   * 
   */
  void display()
  {
    int FRONT_position = FRONT; ///< varaible unutk menyimpan posisi depan antrian
    int REAR_position = REAR; ///< varaible untuk menyimpan posisi belakan antrian

    // cek apakah antrian kosong
    if (FRONT == -1)
    {
      cout << "Queue is empty\n";
      return;
    }

    cout << "\nElements in the queue are...\n";

    // jika FRONT_positoin <= REAR_position, iterasi dari FRONT hingga REAR
    if (FRONT_position <= REAR_position)
    {
      while (FRONT_position <= REAR_position)
      {
        cout << queue_array[FRONT_position] << " ";
        FRONT_position++;
      }

      cout << endl;
    }
    else
    {
      // jika FRONT_position > REAR_position, iterasi FRONT hingga akhir array
      while (FRONT_position <= max - 1)
      {
        cout << queue_array[FRONT_position] << " ";
        FRONT_position++;
      }
      
      FRONT_position = 0;

      // iterasi dari awal array hingga REAR
      while (FRONT_position <= REAR_position)
      {
        cout << queue_array[FRONT_position] << " ";
        FRONT_position++;
      }
      cout << endl;
    }
  }
};

/**
 * @brief Progarm utama untuk menjalankan program
 * 
 * @return int
 */
int main()
{
  Queues q; ///< objek yang digunakan Queues
  char ch; ///< variable untuk menyimpan pilihan menu

  while (true)
  {
    try
    {
      cout << "Menu" << endl;
      cout << "1. Implement insert operation" << endl;
      cout << "2. Implement delete operation" << endl;
      cout << "3. Display values" << endl;
      cout << "4. Exit" << endl;
      cout << "Enter your choice (1-4) : ";
      cin >> ch;
      cout << endl;

      switch (ch)
      {
      case '1':
      {
        q.insert();
        break;
      }
      case '2':
      {
        q.remove();
        break;
      }
      case '3':
      {
        q.display();
        break;
      }
      case '4':
      {
        return 0;
      }
      default:
      {
        cout << "Invalid option!!!" << endl;
        break;
      }
      }
    }
    catch(exception &e)
    {
      cout << "Check for the values entered.\n";
    }
  }
}