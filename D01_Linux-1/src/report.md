## Part 1. Установка OC
- Выводим версию ubuntu с помощью команды cat/etc/issue
- ![alt text](images/part1.png)
## Part 2. Создание пользователя
- создание нового пользователя через sudo useradd -g имя_группы username
- ![alt text](images/part2_1.png)
- cat /etc/passwd чтобы показать созданного пользователя
- ![alt text](images/part2_2.png)
- ![alt text](images/part2_3.png)
## Part 3. Настройка сети ОС
- создаем имя машины командой sudo hostnamectl set-hostname s21-user
- выводим имя машины cat /etc/hostname
- ![alt text](images/part3_1.png)
- установка временной зоны sudo timedatectl set-timezone Asia/Tashkent
- проверка временной зоны timedatectl
- ![alt text](images/part3_2.png)
- вывод названий сетевых интерфейсов ip -br link show
- ![alt text](images/part3_3.png)
- локальный интерфейс, чтобы подключаться к самой машине - lo
- sudo dhclient -v enp0s3 - чтобы получить IP от DHCP сервера 
- ![alt text](images/part3_4.png) 
- DHCP - Dynamic Host Configuration Protocol - протокол динамической настройки узла
- ip route - проверка адресов шлюзов 
- ![alt text](images/part3_5.png) 
- wget -qO- eth0.me - чтобы посмотреть внешний IP 
- ![alt text](images/part3_6.png)
- hostname -I - чтобы посмотреть внутренний IP 
- ![alt text](images/part3_7.png)
- задаем статичные IP, GW, DNS в файле /etc/netplan/00-installer-coinfig.yaml 
- ![alt text](images/part3_8.png)
- перезагружаемся через команду reboot
- ping ya.ru и 1.1.1.1 убеждаемся, что нет пакет лосса 
- ![alt text](images/part3_9.png)
## Part 4. Обновление ОС
- обновить пакеты до последних версий
- ![alt text](images/part4_1.png)
## Part 5. Использование команды sudo
- разрешить юзеру выполнять команду sudo.
- сменить hostname используя sudo.
- ![alt text](report.md)
- sudo - это утилита в Unix-подобных системах, позволяющая пользователю выполнять команды с привилегиями суперпользователя или другого пользователя, если у него есть соответствующие разрешения.
## Part 6. Установка и настройка службы времени
- настройка службы автоматической синхронизации времени
- timedatectl для вывода
- ![alt text](images/part6.png)
## Part 7. Установка и использование текстовых редакторов
- "vim test_vim.txt" > "i" > "tonyflam"  > "Esc" > ":wq"
- ![alt text](images/part7_1.png)
- "nano" "test_nano.txt" > "tonyflam" > "Ctrl+O" > "Ctrl+X"
- ![alt text](images/part7_2.png)
- emacs "test_emacs.txt" > "tonyflam" > "C-x C-s" > "C-x C-c"
- ![alt text](images/part7_3.png)
- Выход без изменений:
- vim ":q!"
- ![alt text](images/part7_4.png)
- nano "Ctrl+X" > "N"
- ![alt text](images/part7_5.png)
- emacs "C-x C-c" > "N"
- ![alt text](images/part7_6.png)
- Поиск
- vim "/строка"
- ![alt text](images/part7_7.png)
- nano "C-w" > "строка"
- ![alt text](images/part7_8.png)
- emacs "C-s" > "строка"
- ![alt text](images/part7_9.png)
- Замена
- vim ":s/" > "подстрока которую меняем" > "подстрока на которую меняем" > "enter"
- ![alt text](images/part7_10.png)
- nano "C-w C-r" > "подстрока которую меняем" > "enter" > "подстрока на которую меняем" > "enter" > "y"
- ![alt text](images/part7_11.png)
- emacs "M-x" > "replace-string" > "enter" > "подстрока которую меняем" > "enter" > "подстрока на которую меняем" > "enter"
- ![alt text](images/part7-12.png)
## Part 8. Установка и базовая настройка сервиса SSHD
- утановка ssh-сервера: sudo apt install openssh-server
- добавление в автозапуск: sudo update-rc.d ssh defaults
- включение службы ssh: sudo systemctl enable ssh
- запуск службы ssh: sudo systemctl start ssh
- изменение порта в ручную: sudo vim /etc/ssh/sshd_config
- смотрим информацию о процессе sshd командой ps -FC sshd. Флаг F выдает подробную информацию, флаг С выдает информацию по дочерним процессам
- перезапускаем службу командой sudo systemctl restart sshd.service
- результат команды netstat -tan:
- ![alt text](images/part8_1.png)
- флаг t - вывод TCP соединений 
- флаг а - вывод прослушиваемых и непрослушиваемых сокетов
- флаг n - вывод в цифрах адреса, порта и имени пользователей
- Proto выводит протоколы, используемые сокетом
- Recv-Q выводит нескопированные пользовательской программой
байты из сокета
- Send-Q выводит не подтвержденные сокетом байты
- Local Address выводит адрес и номер порта локального сокета 
- Foreign Address выводит адрес и номер порта удаленного сокета
- State выводит состояние сокета
- 0.0.0.0 - неопределенный адрес (любой).
## Part 9. Установка и использование утилит top, htop
- uptime 2.21 
- авторизованных пользователей 1
- общая загрузка системы 0.01, 0.02, 0.00
- общее количество процессов 105
- загрузка CPU 0.00
- загрузка памяти 211.3
- pid процесса, занимающего больше всего памяти 1
- pid процесса, занимающего больше всего процессорного времени 1
- ![alt text](images/part9_1.png)
- сортировка по pid
- ![alt text](images/part9_2.png)
- сортировска по Percent_CPU
- ![alt text](images/part9_2.png)
- сортировска по Percent_MEM
- ![alt text](images/part9_3.png)
- сортировка по TIME
- ![alt text](images/part9_4.png)
- фильтр по sshd
- ![alt text](images/part9_5.png)
- syslog найденный через поиск
- ![alt text](images/part9_6.png)
- вывод hostname, clock и uptime
- ![alt text](images/part9_7.png)
## Part 10. Использование утилиты fdisk
- название жесткого диска VBOX-HARDDISK
- размер 25Gib
- секторов 52428800
- ![alt text](images/part10_1.png)
## Part 11. Использование утилиты df
- ![alt text](images/part11_1.png)
- размер раздела 11758760
- размер занятого пространста 5259532
- размер свободного пространства 5880120
- 48% использовано
- тип файловой системы ext-4
- ![alt text](images/part11_2.png)
- размер раздела 12Gb
- размер занятого пространста 5.1Gb
- размер свободного пространства 5.7Gb
- 48% использовано
- тип файловой системы ext-4
## Part 12. Использование утилиты du
- ![alt text](images/part12_1.png)
Флаги:
- h для вывода в человеческом стиле
- B для вывода в нужном размере, далее размер
- s для вывода именно указанных далее директорий
- all для вывода всех файлов, а не только директорий
- ![alt text](images/part12_2.png)
## Part 13. Установка и использование утилиты ncdu
- apt install ncdu
- ncdu /home
- ![alt text](images/part13_1.png)
- ncdu /var
- ![alt text](images/part13_2.png)
- ncdu /var/log
- ![alt text](images/part13_3.png)
## Part 14. Работа с системными журналами
- cat /var/log/dmesg
- ![alt text](images/part14_1.png)
- cat /var/log/syslog
- ![alt text](images/part14_2.png)
- cat /var/log/auth.log
- Jan 28 23:17:01 s21-user CRON[21438]: pam_unix(cron:session): session opened for user root(uid=0) by (uid=0)
- Время: 28 января 23:17:01
- Имя: root
- Метод: pam_unix
- ![alt text](images/part14_3.png)
- sudo grep "Accepted" /var/log/auth.log | tail -n 1
- ![alt text](images/part14_4.png)
- рестарт службы systemctl restart sshd
- ![alt text](images/part14_5.png)
## Part 15. Использование планировщика заданий CRON
- добавляем исполнение uptime каждые 2 мин
- ![alt text](images/part15_1.png)
- проверка "crontab -l"
- ![alt text](images/part15_2.png)
- логи о выполнении cron
- ![alt text](images/part15_3.png)
- "crontab -r" > "crontab -l" для очистки заданий
