/*
 * Prototype.h
 *
 *  Created on: Mar 29, 2013
 *      Author: quix
 */

#ifndef PROTOTYPE_H_
#define PROTOTYPE_H_

enum ImageType
{
	Sat,
	Spot
};

class Image
{
public:
	virtual void draw() = 0;
	static Image* findAndClone(ImageType type);
	virtual ~Image()// = 0;
	{
		std::cout << "Image::dtor()" << std::endl;
	}

protected:
	virtual Image* clone() = 0;
	virtual const ImageType getType() const = 0;
	static void addPrototype(Image* image)
	{
		std::cout << "addPrototype(" << _nextImage << ")" << std::endl;
		_prototypes[_nextImage++] = image;
	}

private:
	static Image* _prototypes[10];
	static int _nextImage;
};

Image* Image::_prototypes[];
int Image::_nextImage = 0;

Image* Image::findAndClone(ImageType type)
{
	for (int i = 0; i < _nextImage; _nextImage++)
		if (type == _prototypes[i]->getType())
			return _prototypes[i]->clone();
	return 0;
};

class SatImage : public Image
{
public:
	void draw()
	{
		std::cout << "SatImage::draw() " << _id << std::endl;
	}
	//~SatImage() {}

protected:
	Image* clone()
	{
		return new SatImage(1);
	}
	const ImageType getType() const
	{
		return Sat;
	}
private:
	SatImage(int dummy)
	{
		_id = _count++;
		std::cout << "Sat(" << _id << ")" << std::endl;
	}
	SatImage()
	{
		addPrototype(this);
	}
	static SatImage _satImage;
	int _id;
	static int _count;
};

SatImage SatImage::_satImage;
int SatImage::_count = 1;

class SpotImage : public Image
{
	void draw()
	{
		std::cout << "SpotImage::draw() " << _id << std::endl;
	}
	//~SpotImage() {}

protected:
	Image* clone()
	{
		return new SpotImage(1);
	}
	const ImageType getType() const
	{
		return Spot;
	}
private:
	SpotImage(int dummy)
	{
		_id = _count++;
		std::cout << "Spot(" << _id << ")" << std::endl;
	}
	SpotImage()
	{
		addPrototype(this);
	}

	int _id;
	static int _count;
	static SpotImage _spotImage;
};

SpotImage SpotImage::_spotImage;
int SpotImage::_count = 1;

#endif /* PROTOTYPE_H_ */
