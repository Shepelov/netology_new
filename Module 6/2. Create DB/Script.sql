create table if not exists genres(
	id serial primary key,
	name varchar(20) not null
);

create table if not exists artists(
	id serial primary key,
	name varchar(40) not null
);

create table if not exists genres_artists(
	genre_id integer references genres(id),
	artist_id integer references artists(id),
	primary key(genre_id, artist_id)
);

create table if not exists albums(
	id serial primary key,
	name varchar(40) not null,
	year integer not null
);

create table if not exists artists_albums(
	artist_id integer references artists(id),
	album_id integer references albums(id),
	primary key(artist_id, album_id)
);

create table if not exists tracks(
	id serial primary key,
	name varchar(40) not null,
	duration time not null,
	album integer references albums(id)
);

create table if not exists collections(
	id serial primary key,
	name varchar(40) not null
);

create table if not exists collections_tracks(
	collection_id integer references collections(id),
	track_id integer references tracks(id),
	primary key(collection_id, track_id)
);