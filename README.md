# README #

### What is this repository for? ###

* Quick summary
viagogo Intern/Graduate Developer Test

* Version: 1.0

* External dependencies: None

### How do I get set up? ###

1) Download sources

2) Open Visual Studio solution file

3) Compile

### Feature improvements ###

* Introduce boost + ICU libraries for better internationalization and Unicode support.
* To support multiple events single event object shall be substituted with vector of events. Search tool should be changed, to firstly display every event from closest location, then proceed to further events. In database, each event would have assigned it's location ID.
* Much bigger world should be divided into groups of locations: countries, shires (or other administrative division), towns, post codes, etc., with every group assigned an unique ID (numbers, letters, or both). To search for events in specific location, user would pick up a location (it's ID would be a combination of all groups it belongs to). Picking up a location would be done by lists with auto-complete option, after choosing each level, the search query will be more narrow and cover more specific area. 
* To handle more users and bigger world, external database is compulsory. Events, tickets, locations (with appropriate groups) and users data should be stored in corresponding tables.

### Who do I talk to? ###

Bartłomiej Szostek
szostek.bartek@gmail.com