using _353503_ABDULOV_LAB1_2;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Data;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
  
namespace _353503_ABDULOV_LAB1_2
{
    public class MyCustomCollection<T> : ICustomCollection<T>{
        private ElementOfCollection first, current;
        private int count;

        private class ElementOfCollection{
            public ElementOfCollection next;
            public T item;
            public ElementOfCollection(T item){
                this.item = item;
                next = null;
            }
        }

        public MyCustomCollection(){
            first = null;
            current = null;
            count = 0;
        }
        private ElementOfCollection getIndexElement(int index){
            if (count <= index) throw new IndexOutOfRangeException();

            ElementOfCollection neededItem = first;
            for (int i = 0; i < index; i++){
                neededItem = neededItem.next;
            }

            return neededItem;
        }

        private ElementOfCollection getPreviousElement(ElementOfCollection el){
            ElementOfCollection neededItem = first;

            if (first != null){

                while (!(neededItem.next.Equals(el))){
                    if (neededItem.next == null){
                        return null;
                    }

                    neededItem = neededItem.next;
                }
            }
            return neededItem;
        }

        private ElementOfCollection getLastElement(){
            ElementOfCollection last = first;
            for (int i = 0; i < count - 1; i++){
                last = last.next;
            }
            return last;
        }
        public T this[int index]{
            get => getIndexElement(index).item;
            set => getIndexElement(index).item = value;
        }

        private ElementOfCollection find(T item){
            ElementOfCollection curr = first;

            while (!curr.item.Equals(item) && curr.next != null){
                curr = curr.next;
            }

            if (!curr.item.Equals(item)){
                return null;
            }

            return curr;
        }

        public int Count => count;

        public void Add(T item){
            if (first == null) {
                first = new ElementOfCollection(item);
                current = first;
            } else
                getLastElement().next = new ElementOfCollection(item);

            count++;
        }

        public T Current(){
            if (current == null)
                throw new Exception("Текущего элемента не существует");

            return current.item;
        }

        public void Next() {
            if (current == null) return;

            current = current.next;
        }

        public void Remove(T item){
            ElementOfCollection delItem = find(item);

            if (delItem != null){
                if (delItem == first)
                {
                    first = delItem.next;
                    if (current == delItem) current = first;

                } else if (delItem == getLastElement()){
                    if (current == delItem) {
                        current = getPreviousElement(delItem);
                        current.next = null;
                    } else {
                        getPreviousElement(delItem).next = null;
                    }

                }else{
                    getPreviousElement(delItem).next = delItem.next;
                    if (current == delItem) current = delItem.next;
                }
                count--;
            }else{
                throw new Exception("Удаление не существующего элемента");
            }
        }

        public T RemoveCurrent(){
            if (current == null) throw new Exception("Текущего элемента не существует");
            T item = current.item;

            if (current == first){
                if (current.next == null){
                    first = null;
                    current = first;

                }else{
                    first = current.next;
                    current = first;
                }

            }else if (current == getLastElement()){
                current = getPreviousElement(current);
                current.next = null;

            }else{
                getPreviousElement(current).next = current.next;
                current = current.next;
            }

            count--;
            return item;
        }

        public void Reset(){
            current = first;
        }

        IEnumerator<T> IEnumerable<T>.GetEnumerator(){
            ElementOfCollection tmp = current;
            Reset();
            while (current != null){
                yield return current.item;
                Next();
            }
            current = tmp;
        }

        IEnumerator IEnumerable.GetEnumerator(){
            return ((IEnumerable<T>)this).GetEnumerator();
        }
    }
}
