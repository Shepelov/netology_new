-- добавляем жанры
insert into genres values (1, 'rock');
insert into genres values (2, 'pop');
insert into genres values (3, 'rap');

-- добавляем исполнителей
insert into artists values (1, 'Madonna');
insert into artists values (2, 'Rammstein');
insert into artists values (3, 'Britney Spears');
insert into artists values (4, 'Big Baby Tape');

-- добавляем связи исполнитель-жанр
insert into genres_artists values (2, 1);
insert into genres_artists values (1, 2);
insert into genres_artists values (2, 3);
insert into genres_artists values (3, 4);

-- добавляем альбомы
insert into albums values (1, 'Madame X', 2018);
insert into albums values (2, 'Mutter', 2001);
insert into albums values (3, 'Baby One More Time', 1999);
insert into albums values (4, 'Dragonborn', 2018);
insert into albums values (5, 'American Life', 2003);
insert into albums values (6, 'Glory', 2019);


-- добавляем связи исполнитель-альбом
insert into artists_albums values (1, 1);
insert into artists_albums values (2, 2);
insert into artists_albums values (3, 3);
insert into artists_albums values (4, 4);
insert into artists_albums values (1, 5);
insert into artists_albums values (3, 6);

-- добавляем треки
insert into tracks values (1, 'Medellin', '0:04:58', 1);
insert into tracks values (2, 'Bitch I’m Loca', '0:02:50', 1);
insert into tracks values (3, 'Feuer frei!', '0:03:08', 2);
insert into tracks values (4, 'Mein Herz brennt', '0:04:40', 2);
insert into tracks values (5, 'Crazy', '0:03:17', 3);
insert into tracks values (6, 'Born to Make You Happy', '0:04:03', 3);
insert into tracks values (7, 'Dragonborn', '0:03:09', 4);
insert into tracks values (8, 'Project X', '0:01:48', 4);
insert into tracks values (9, 'American Life', '0:04:58', 5);
insert into tracks values (10, 'Hollywood', '0:04:24', 5);
insert into tracks values (11, 'My Invitation', '0:03:19', 6);
insert into tracks values (12, 'Private Show', '0:03:54', 6);

-- добавляем сборники
insert into collections values (1, 'Star Collection 2016', 2016);
insert into collections values (2, 'Star Collection 2018', 2018);
insert into collections values (3, 'Star Collection 2020', 2020);
insert into collections values (4, 'Star Collection 2022', 2022);

-- добавляем связи сборник-трек
insert into collections_tracks values (1, 2);
insert into collections_tracks values (1, 12);
insert into collections_tracks values (1, 8);
insert into collections_tracks values (2, 1);
insert into collections_tracks values (2, 2);
insert into collections_tracks values (2, 10);
insert into collections_tracks values (3, 5);
insert into collections_tracks values (3, 7);
insert into collections_tracks values (3, 8);
insert into collections_tracks values (4, 10);
insert into collections_tracks values (4, 11);
insert into collections_tracks values (4, 4);