using _353503_ABDULOV_LAB6;
using System;
using System.Collections.Generic;
using System.IO;
using System.Text.Encodings.Web;
using System.Text.Json;
using System.Text.Unicode;

namespace ClassLibrary_LAB6{
    public class FileService<T> : IFileService<T>{
        public IEnumerable<Employee> ReadFile(string fileName){
            string path = "D:\\C#\\353503_ABDULOV_LAB6\\Files\\" + fileName + ".json";
            string jsonString = File.ReadAllText(path);
            
            return JsonSerializer.Deserialize<List<Employee>>(jsonString);
        }

        public void SaveData(IEnumerable<Employee> data, string fileName){
            var options = new JsonSerializerOptions{
                WriteIndented = true,
                Encoder = JavaScriptEncoder.Create(UnicodeRanges.All)
            };

            string jsonString = JsonSerializer.Serialize(data.ToList(), options);
            string path = "D:\\C#\\353503_ABDULOV_LAB6\\Files\\" + fileName + ".json";

            File.WriteAllText(path, jsonString);
        }
    }
}
