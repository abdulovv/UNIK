using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading.Tasks.Dataflow;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace _353503_ABDULOV_LAB4{
    public class FileService<T> : IFileService<T>{
        public IEnumerable<string> ReadFile(string fileName){
            string path  = "D:\\C#\\353503_ABDULOV_LAB4\\353503_ABDULOV_LAB4\\File\\" + fileName + ".bin";
            using (FileStream stream = new FileStream(path, FileMode.Open, FileAccess.Read))
            using (BinaryReader reader = new BinaryReader(stream)){

                string line;
                while (true){
                    try{
                        line = reader.ReadString();
                    }catch (EndOfStreamException){
                        stream.Close();
                        break;
                    }
                    yield return line;
                }
            }
        }
        public void SaveData(IEnumerable<Tenant> data, string fileName) {
            string path = "D:\\C#\\353503_ABDULOV_LAB4\\353503_ABDULOV_LAB4\\File\\" + fileName + ".bin";

            using (BinaryWriter writer = new BinaryWriter(File.Open(fileName, FileMode.Open)))
            {


                foreach (var a in data)
                {
                    writer.Write(a.name);
                    writer.Write(a.floor);
                    writer.Write(a.isApartmentForRent);


                    //byte[] bytes = Encoding.UTF8.GetBytes(a.ToString());
                    //writer.Write(bytes);
                }



            }
        }

    }
    
}
