#include "music.h"

QString Music::album() const
{
    return m_album;
}

void Music::setAlbum(const QString &newAlbum)
{
    m_album = newAlbum;
}

QString Music::artist() const
{
    return m_artist;
}

void Music::setArtist(const QString &newArtist)
{
    m_artist = newArtist;
}

QString Music::notes() const
{
    return m_notes;
}

void Music::setNotes(const QString &newNotes)
{
    m_notes = newNotes;
}

QDate Music::release() const
{
    return m_release;
}

void Music::setRelease(const QDate &newRelease)
{
    m_release = newRelease;
}
