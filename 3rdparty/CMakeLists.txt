# add_subdirectory(taglib)
add_library(taglib STATIC
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/audioproperties.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/fileref.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/tag.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/tagunion.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/tagutils.cpp

    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/ape/apefile.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/ape/apefooter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/ape/apeitem.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/ape/apeproperties.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/ape/apetag.cpp

    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/asf/asfattribute.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/asf/asffile.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/asf/asfpicture.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/asf/asfproperties.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/asf/asftag.cpp

    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/flac/flacfile.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/flac/flacmetadatablock.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/flac/flacpicture.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/flac/flacproperties.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/flac/flacunknownmetadatablock.cpp

    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/it/itfile.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/it/itproperties.cpp

    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mod/modfile.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mod/modfilebase.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mod/modproperties.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mod/modtag.cpp

    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mp4/mp4atom.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mp4/mp4coverart.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mp4/mp4file.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mp4/mp4item.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mp4/mp4properties.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mp4/mp4tag.cpp

    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpc/mpcfile.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpc/mpcproperties.cpp

    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/mpegfile.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/mpegheader.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/mpegproperties.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/xingheader.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v1/id3v1genres.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v1/id3v1tag.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v2/id3v2extendedheader.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v2/id3v2footer.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v2/id3v2frame.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v2/id3v2framefactory.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v2/id3v2header.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v2/id3v2synchdata.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v2/id3v2tag.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v2/frames/attachedpictureframe.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v2/frames/chapterframe.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v2/frames/commentsframe.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v2/frames/eventtimingcodesframe.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v2/frames/generalencapsulatedobjectframe.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v2/frames/ownershipframe.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v2/frames/podcastframe.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v2/frames/popularimeterframe.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v2/frames/privateframe.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v2/frames/relativevolumeframe.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v2/frames/synchronizedlyricsframe.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v2/frames/tableofcontentsframe.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v2/frames/textidentificationframe.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v2/frames/uniquefileidentifierframe.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v2/frames/unknownframe.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v2/frames/unsynchronizedlyricsframe.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v2/frames/urllinkframe.cpp

    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/ogg/oggfile.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/ogg/oggpage.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/ogg/oggpageheader.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/ogg/xiphcomment.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/ogg/flac/oggflacfile.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/ogg/opus/opusfile.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/ogg/opus/opusproperties.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/ogg/speex/speexfile.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/ogg/speex/speexproperties.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/ogg/vorbis/vorbisfile.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/ogg/vorbis/vorbisproperties.cpp

    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/riff/rifffile.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/riff/aiff/aifffile.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/riff/aiff/aiffproperties.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/riff/wav/infotag.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/riff/wav/wavfile.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/riff/wav/wavproperties.cpp

    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/s3m/s3mfile.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/s3m/s3mproperties.cpp

    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/toolkit/tbytevector.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/toolkit/tbytevectorlist.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/toolkit/tbytevectorstream.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/toolkit/tdebug.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/toolkit/tdebuglistener.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/toolkit/tfile.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/toolkit/tfilestream.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/toolkit/tiostream.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/toolkit/tpropertymap.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/toolkit/trefcounter.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/toolkit/tstring.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/toolkit/tstringlist.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/toolkit/tzlib.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/trueaudio/trueaudiofile.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/trueaudio/trueaudioproperties.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/wavpack/wavpackfile.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/wavpack/wavpackproperties.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/xm/xmfile.cpp
    ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/xm/xmproperties.cpp
)


# if(NOT ZLIB_SOURCE)
#   find_package(ZLIB)
#   if(ZLIB_FOUND)
#     target_compile_definitions(taglib PRIVATE -DHAVE_ZLIB)
#   endif()
# endif()


if (${CMAKE_CXX_COMPILER_ID} MATCHES "GNU")
    target_compile_definitions(taglib PRIVATE -DHAVE_GCC_ATOMIC -DHAVE_GCC_BYTESWAP -DHAVE_VSNPRINTF -DHAVE_VSNPRINTF_S)
endif()

target_include_directories(taglib PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/wrapper/taglib
        )
target_include_directories(taglib PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/taglib
        ${CMAKE_CURRENT_LIST_DIR}/taglib/3rdparty
        ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib
        ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/ape
        ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/asf
        ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/flac
        ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/it
        ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mod
        ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mp4
        ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpc
        ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg
        ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v1
        ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v2
        ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/mpeg/id3v2/frames
        ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/ogg
        ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/ogg/flac
        ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/ogg/opus
        ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/ogg/speex
        ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/ogg/vorbis
        ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/riff
        ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/riff/aiff
        ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/riff/wav
        ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/s3m
        ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/toolkit
        ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/trueaudio
        ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/wavpack
        ${CMAKE_CURRENT_LIST_DIR}/taglib/taglib/xm
        )