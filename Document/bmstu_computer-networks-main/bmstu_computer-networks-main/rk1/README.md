
### **Сопоставьте утверждение с типом сокета, для которого оно верно**:  
TCP:
* Создается с помощью вызова функции socket(AF_INET, SOCK_STREAM)  
* Сервер может выполнять вызов функции accept() для этого сокета
* После запроса нового клиента, создает новый сокет для его обработки,
* Обеспечивает надежную, упорядоченную передачу данных 

UDP:
* Создается вызовом функции (AF_INET, SOCK_DGRAM)
* Отправитель явно добавляет адрес получателя и номер порта к каждому пакету такого сокета
* Может выполнять прием данных от разных клиентов на одном и том же сокете
* Обеспечивает ненадежную передачу данных

### Укажите имя/hostname устройства, на котором располагается сайт wiki.bmstu.ru. Воспользуйтесь для этого утилитой tracert (Windows)/ traceroute (Linux/Mac).
h135.net40.bmstu.ru

### Укажите имя/hostname устройства, на котором располагается сайт bmstu.ru. Воспользуйтесь для этого утилитой tracert (Windows)/ traceroute (Linux/Mac).
h247.net50.bmstu.ru

### Когда приложение использует TCP-сокет, какие услуги транспортного уровня оно получает?
* Надежная доставка сообщений - все отброшенные маршрутизатором из-за переполнения буфера 
пакеты будут восстановлены и переданы повторно, 
* Гарантируется, что отправитель не будет отправлять пакеты 
со скоростью, допускающей переполнение буфера получателя, 
* Гарантируется, что отправитель не будет отправлять 
данные со скоростью, допускающей возникновение перегрузки канала связи.

### Укажите, примером какого процесса является следующее описание: Сетевой уровень получает инкапсулированный пакет сетевого уровня от канального, выполняет проверку адреса. Если адрес совпадает, из пакета извлекается сегмент, остатки пакета отбрасываются.

Деинкапсуляция

### В примере полного доменного имени ru.wikipedia.org. доменом третьего уровня является
ru

### В примере полного доменного имени ru.wikipedia.org. доменом верхнего уровня является
org

### На каком из уровней модели OSI выполняется цифровая модуляция?
Физический

### Для какого из уровней модели OSI единицей передачи данных является бит?
Физический

### Для какого из уровней модели OSI единицей передачи данных является фрейм?
Канальный


### Почему вместо использования протокола UDP нельзя напрямую передавать IP-пакет?
* Не будет известен процесс-получатель, 
* Невозможно будет выполнить демультиплексирование

### Демультиплексированием на транспортном уровне называется процедура
:heavy_check_mark: Получения сегмента транспортного уровня от сетевого уровня, извлечение данных, доставка данных корректному сокету  
:x: Получения сегмента транспортного уровня от сетевого уровня, извлечение данных, определение IP-адреса для данных и передача сегмента вместе с IP-адресом сетевому уровню  
:x: Получения данных от сокета, добавление заголовка транспортного уровня, передача получившегося сегмента сетевому уровню  
:x: Получение данных от нескольких сокетов, связанных с одним ip, добавление IP-адреса назначения к каждому блоку данных, объединение их и передача полученного сегмента сетевому уровню  

### Ресурсная запись типа "PTR" используется при
Обратном запросе

### Сопоставьте задачу, решаемую каждым из протоколов с названием протокола
**IMAP:** При получении почты письмо копируется с сервера на клиент  
**POP3/IMAP:** Используется почтовым клиентом для получения письма с сервера  
**SMTP:** Используется почтовым клиентом для передачи письма на сервер  
**POP3:** При получении почты письмо перемещается с сервера на клиент, на сервере письмо удаляется  

### Какие значения полей флагов используются в процессе закрытия соединения TCP?
ACK, FIN

### Какие значения полей флагов используются в процессе открытия соединения TCP?
:heavy_check_mark: ACK
:heavy_check_mark: SYN
:x: FIN
:x: URG
:x: PSH
:x: RST

### В каком состоянии находится сеанс TCP после завершения тройного рукопожатия? 
ESTABLISHED

### Мультиплексированием на транспортном уровне называется процедура
Получения данных от сокета, добавление заголовка транспортного уровня, передача получившегося сегмента сетевому уровню

### Когда приложение использует UDP-сокет, какие услуги транспортного уровня оно получает?
* Будет предпринята попытка доставки данных в соответствии с имеющимися возможностями, но никаких гарантий не предоставляется

### Какие из утверждений о коммутации пакетов верны?
:heavy_check_mark: Адрес получателя необходимо передавать с каждым сообщением,   
:heavy_check_mark: Система приоритетов позволяет продвигать определенные пакеты с меньшей задержкой,   
:heavy_check_mark: Эффективность использования пропускной способности выше, чем при коммутации каналов.  

### Какие из утверждений о коммутации каналов верны?
:heavy_check_mark: Соединение между двумя абонентами всегда требует резервирования ресурсов    
:heavy_check_mark: Скорость передачи данных фиксирована    
:heavy_check_mark: Для передачи данных образуется фиксированный составной канал связи    
:x: Пропускная способность канала всегда расходуется рационально    
:x: Адрес получателя необходимо передавать с каждым сообщением    
:x: Соединение между двумя абонентами всегда устанавливается гарантированно   

### Укажите максимальный допустимый номер общеизвестного (well-known) порта по умолчанию
1023

### Укажите длину адреса (в битах), который является частью DNS записи типа AAAA
128

### Укажите длину адреса (в битах), который является частью DNS записи типа A
32

### В ресурсной записи DNS типа "A" в базе данных DNS-сервера содержится
Имя хоста и IPv4-адрес

### Какие виды устройств могут поддерживать полудуплексное (half-duplex) соединение?
* Концентратор, 
* Маршрутизатор, 
* Повторитель, 
* Мост, 
* Коммутатор.

### Какие виды устройств могут поддерживать полнодуплексное соединение?
* Маршрутизатор  
* Мост  
* Коммутатор  

### Какие из указанных стандартов используют оптоволоконный кабель в качестве среды передачи данных?
100Base-FX, 10Base-F

Не используют: 10Base-5, IEEE 802.15.4, 10Base-Т, 10Base-2

### Если цель - максимальная длина сегмента, то оптимальным решением при выборе типа кабеля является
:heavy_check_mark: Одномодовый оптоволоконный  
:x: Толстый коаксиальный  
:x: Медная витая пара  
:x: Многомодовый оптоволоконный  
:x: Тонкий коаксиальный  

### За передачу информации серверу в протоколе HTTP отвечают методы
:heavy_check_mark: PUT  
:heavy_check_mark: DELETE  
:heavy_check_mark: POST  
:x: GET  
:x: HEAD  

### За передачу информацию клиенту в протоколе HTTP отвечают методы
:heavy_check_mark: GET  
:heavy_check_mark: HEAD  

### Какие задачи решает протокол IMAP?
:heavy_check_mark: Копирование сообщений с почтового сервера на клиент   
:heavy_check_mark: Управление несколькими почтовыми ящиками   
:x: Отправка сообщений с клиента на сервер    
:x: Передача сообщений между MTA   
:x: Перемещение сообщений с почтового сервера на клиент (удаление на сервере)   

### Когда приложение использует TCP-сокет, какие услуги транспортного уровня оно получает?
:heavy_check_mark: Гарантируется, что отправитель не будет отправлять данные со скоростью, допускающей возникновение перегрузки канала связи  
:heavy_check_mark: Надежная доставка сообщений - все отброшенные маршрутизатором из-за переполнения буфера пакеты будут восстановлены и переданы повторно  
:heavy_check_mark: Гарантируется, что отправитель не будет отправлять пакеты со скоростью, допускающей переполнение буфера получателя  
:x: Будет предпринята попытка доставки данных в соответствии с имеющимися возможностями, но никаких гарантий не предоставляется  
:x: Гарантируется определенное время, за которое данные будут доставлены  
:x: Можно указать минимальную необходимую пропускную способность сети  

### На каком номере порта открывается управляющее соединение FTP?
21

### Какие из приведенных определений верны?
:heavy_check_mark: DNS - протокол, позволяющий по символьному имени определить ip-адрес  
:heavy_check_mark: DNS - протокол, позволяющий по ip-адресу определить символьное имя  
:heavy_check_mark: SMTP - протокол электронной почты, позволяющий передавать данные между почтовыми серверами  
:heavy_check_mark: DHCP - протокол, позволяющий назначать адреса сетевого уровня устройствам сети  
:x: DHCP - протокол, позволяющий назначать адреса канального уровня устройствам сети  
:x: HTTP - защищенный протокол, отвечающий за передачу гипертекстовых данных между сервером и клиентом  

### Укажите код отклика SMTP сервера после успешного установления соединения.
220

### Что можно сказать о пакете HTTP, в заголовке которого указано HTTP/1.1 204 No Content
:heavy_check_mark: Это сообщение-ответ  
:heavy_check_mark: Код 204 означает успешную обработку запроса  
:heavy_check_mark: No content означает, что запрос успешно выполнен и пересылать больше нечего  
:x: No content означает отсутствие требуемой страницы на сервере  
:x: Код 204 означает неуспешную обработку запроса  
:x: Это сообщение-запрос   

### Укажите, примером какого процесса является следующее описание:
Сетевой уровень получает инкапсулированное сообщение транспортного уровня, добавляет к нему заголовок с ipv4 и ipv6 адресом для возможности маршрутизации

:heavy_check_mark: Инкапсуляция    
:x: Деинкапсуляция   
:x: Мультиплексирование    
:x: Демультиплексирование  
:x: Ни один ответ не подходит  

### Укажите функцию, которая позволяет серверу на основе системного сокета обрабатывать входящие соединения.
accept

### Укажите максимальный допустимый номер динамического порта по умолчанию
65535
