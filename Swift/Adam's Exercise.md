# Adam's Exercise

Ref: http://blog.adamcameron.me/2017/11/that-arraymap-quandary-implemented-in.html

Remap this:
```
[
    "2008-11-08" => "Jacinda",
    "1990-10-27" => "Bill",
    "2014-09-20" => "James",
    "1979-05-24" => "Winston"
]
```
to this:
```
array(4) {
  '2008-11-08' =>
  class IndexedPerson#3 (2) {
    public $date =>
    string(10) "2008-11-08"
    public $name =>
    string(7) "Jacinda"
  }
  '1990-10-27' =>
  class IndexedPerson#4 (2) {
    public $date =>
    string(10) "1990-10-27"
    public $name =>
    string(4) "Bill"
  }
  '2014-09-20' =>
  class IndexedPerson#5 (2) {
    public $date =>
    string(10) "2014-09-20"
    public $name =>
    string(5) "James"
  }
  '1979-05-24' =>
  class IndexedPerson#6 (2) {
    public $date =>
    string(10) "1979-05-24"
    public $name =>
    string(7) "Winston"
  }
}
```
## Solution
``` swift
class IndexedPerson {
    var date: String
    var name: String
    
    init(date: String, name: String) {
        self.date = date
        self.name = name
    }
    
    func toString() -> String {
        return("{date: \(date), name: \(name)}" )
    }
    
}

let peopleData = [
    "2008-11-08": "Jacinda", 
    "1990-10-27": "Bill", 
    "2014-09-20": "James", 
    "1979-05-24": "Winston"
    ]

let people = peopleData.map { 
    key, value in 
    (IndexedPerson(date: key, name: value))
    }
    
for person in people {
    print("\(person.date) => \(person.toString())")
}
```

## Run
https://repl.it/repls/LoudSnappyScandisk
