/* =========================
   MOBILE MENU
========================= */

const menuBtn = document.getElementById("menuBtn");
const navMenu = document.getElementById("navMenu");
const navLinks = document.querySelectorAll(".nav-link");

menuBtn.addEventListener("click", () => {

    navMenu.classList.toggle("active");

    const icon = menuBtn.querySelector("i");

    if (navMenu.classList.contains("active")) {
        icon.classList.remove("fa-bars");
        icon.classList.add("fa-xmark");
    } else {
        icon.classList.remove("fa-xmark");
        icon.classList.add("fa-bars");
    }

});


/* Close mobile menu */

navLinks.forEach(link => {

    link.addEventListener("click", () => {

        navMenu.classList.remove("active");

        const icon = menuBtn.querySelector("i");

        icon.classList.remove("fa-xmark");
        icon.classList.add("fa-bars");

    });

});


/* =========================
   TYPING EFFECT
========================= */

const typingElement = document.getElementById("typing");

const words = [
    "Graphic Designer",
    "Brand Designer",
    "Visual Designer",
    "Creative Designer"
];

let wordIndex = 0;
let charIndex = 0;
let deleting = false;

function typeEffect() {

    const currentWord = words[wordIndex];

    if (!deleting) {

        typingElement.textContent =
            currentWord.substring(0, charIndex + 1);

        charIndex++;

        if (charIndex === currentWord.length) {

            deleting = true;

            setTimeout(typeEffect, 1600);

            return;
        }

    } else {

        typingElement.textContent =
            currentWord.substring(0, charIndex - 1);

        charIndex--;

        if (charIndex === 0) {

            deleting = false;

            wordIndex++;

            if (wordIndex >= words.length) {
                wordIndex = 0;
            }

        }

    }

    const speed = deleting ? 55 : 90;

    setTimeout(typeEffect, speed);
}

typeEffect();


/* =========================
   SCROLL REVEAL
========================= */

const revealElements =
    document.querySelectorAll(".reveal");

const revealObserver =
    new IntersectionObserver(
        (entries, observer) => {

            entries.forEach(entry => {

                if (entry.isIntersecting) {

                    entry.target.classList.add("show");

                    observer.unobserve(entry.target);

                }

            });

        },
        {
            threshold: 0.12
        }
    );


revealElements.forEach(element => {
    revealObserver.observe(element);
});


/* =========================
   ACTIVE NAVIGATION
========================= */

const sections =
    document.querySelectorAll("section[id]");

window.addEventListener("scroll", () => {

    let currentSection = "";

    sections.forEach(section => {

        const sectionTop =
            section.offsetTop - 150;

        const sectionHeight =
            section.offsetHeight;

        if (
            window.scrollY >= sectionTop &&
            window.scrollY < sectionTop + sectionHeight
        ) {

            currentSection =
                section.getAttribute("id");

        }

    });


    navLinks.forEach(link => {

        link.classList.remove("active");

        if (
            link.getAttribute("href") ===
            `#${currentSection}`
        ) {

            link.classList.add("active");

        }

    });

});


/* =========================
   PROJECT FILTER
========================= */

const filterButtons =
    document.querySelectorAll(".filter-btn");

const projectCards =
    document.querySelectorAll(".project-card");


filterButtons.forEach(button => {

    button.addEventListener("click", () => {

        /* Remove active */

        filterButtons.forEach(btn => {
            btn.classList.remove("active");
        });

        /* Add active */

        button.classList.add("active");


        const filter =
            button.getAttribute("data-filter");


        projectCards.forEach(card => {

            const category =
                card.getAttribute("data-category");


            if (
                filter === "all" ||
                category === filter
            ) {

                card.style.display = "block";

                setTimeout(() => {

                    card.style.opacity = "1";
                    card.style.transform =
                        "scale(1)";

                }, 50);

            } else {

                card.style.opacity = "0";
                card.style.transform =
                    "scale(0.95)";

                setTimeout(() => {

                    card.style.display = "none";

                }, 300);

            }

        });

    });

});


/* =========================
   CONTACT FORM
========================= */

const contactForm =
    document.getElementById("contactForm");

const formMessage =
    document.getElementById("formMessage");


contactForm.addEventListener("submit", function (event) {

    event.preventDefault();


    const name =
        document.getElementById("name").value.trim();

    const email =
        document.getElementById("email").value.trim();

    const message =
        document.getElementById("message").value.trim();


    if (!name || !email || !message) {

        formMessage.style.color = "#ff6b6b";

        formMessage.textContent =
            "Please fill all required fields.";

        return;

    }


    formMessage.style.color = "#62df7a";

    formMessage.textContent =
        "Thank you! Your message has been received.";


    contactForm.reset();

});


/* =========================
   HEADER BACKGROUND
========================= */

const header =
    document.getElementById("header");


window.addEventListener("scroll", () => {

    if (window.scrollY > 50) {

        header.style.background =
            "rgba(8, 8, 11, 0.95)";

    } else {

        header.style.background =
            "rgba(8, 8, 11, 0.75)";

    }

});


/* =========================
   MOUSE PARALLAX
========================= */

const designCard =
    document.querySelector(".design-card");

const heroVisual =
    document.querySelector(".hero-visual");


heroVisual.addEventListener("mousemove", (event) => {

    if (window.innerWidth < 750) return;


    const rect =
        heroVisual.getBoundingClientRect();

    const x =
        event.clientX - rect.left;

    const y =
        event.clientY - rect.top;


    const centerX =
        rect.width / 2;

    const centerY =
        rect.height / 2;


    const rotateX =
        (y - centerY) / 35;

    const rotateY =
        (centerX - x) / 35;


    designCard.style.transform =
        `rotateX(${rotateX}deg)
         rotateY(${rotateY}deg)
         rotate(3deg)`;

});


heroVisual.addEventListener("mouseleave", () => {

    designCard.style.transform =
        "rotate(5deg)";

});


/* =========================
   BACK TO TOP
========================= */

const backTop =
    document.querySelector(".back-top");


backTop.addEventListener("click", (event) => {

    event.preventDefault();

    window.scrollTo({
        top: 0,
        behavior: "smooth"
    });

});