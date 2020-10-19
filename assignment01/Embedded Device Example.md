An example of an embedded system is an RFID system, which can be used across different industries from book stores - to track books and prevent theft, to manufacturing plants - to track parts.

## How its embedded system works
An RFID reader picks up an RF signal from an RFID tag (active or passive tag). The RFID reader then processes the RF signal and converts it into data which is then compared against an internal database, or transferred through a communication interface to a host computer system.  

## What design challenges it presents
Here are some examples that need to be taken into consideration during the design phase: 
* Read range: active tags have a longer read range than passive tags; however, they require an internal power source so they have a limited lifespan and a bigger profile making them difficult to embed in small items, whereas passive tags have an indefinite lifespan and a smaller profile that allows them to be embedded in small items like books. 
* Security: risk of unauthorized reading of RFID tags – including those embedded in credit cards and passports. Some active tags allow for encryption. 
* Cost: active tags are more expensive than passive tags  
* Reliability of RF signal: it can be blocked by metal; RF collision (more than one tag can respond at the same time) 
* Data rate: RF readers have different data rates which can increase the price even more 
* Memory: limited memory. The RFID reader can store logic to perform based on reading an RFID tag (e.g. opening a door) and comparing it to its internal database. For more complex operations or larger databases, it would need to be connected to a a computer system (e.g. a company database that needs to be updated in real time). 
