-- 1
select g.name, count(a.name) from genres_artists ga
join genres g on ga.genre_id = g.id
join artists a on ga.artist_id = a.id 
group by g.name; 

-- 2
select count(*) from tracks t 
join albums a on t.album = a.id
where a."year" between 2019 and 2020;

-- 3
select a.name, avg (t.duration) from tracks t 
join albums a on t.album = a.id 
group by a.name;

-- 4
select distinct ar.name from artists_albums aa
join albums a on aa.album_id = a.id 
join artists ar on aa.artist_id = ar.id 
where a.year != 2020;

-- 5
select distinct c.name from collections_tracks ct 
join collections c on ct.collection_id = c.id 
join tracks t on ct.track_id = t.id 
join albums a on t.album = a.id 
join artists_albums aa on a.id = aa.album_id 
join artists ar on aa.artist_id = ar.id 
where ar.name = 'Britney Spears'